<?php

namespace App\Http\Controllers;


use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Storage;

use App\Models\Item;
use App\Models\Categories;

class ItemController extends Controller{
    
    //show items page
    public function index(){
        return view('items.index', ['items' => Item::orderBy('title', 'desc')->get()]);
       
    }

    
    //create item
    public function create(){
        $categories = Categories::all();
       
        return view('items.create', compact('categories'));
        

    }

    
    //store a new item in the databse
    public function store(Request $request){
       
       
        // Validate the request data
    try {
        $request->validate([
            'title' => 'required|unique:items,title|max:255',
            'cat_id' => 'required|exists:categories,id',
        ]);

       
        } catch (\Illuminate\Validation\ValidationException $e) {
            // If validation fails, redirect back with errors and the previously entered values
            return redirect('/items/create')
                ->withErrors($e->validator)
                ->withInput();
        }
        // If validation passes, create a new item
        $category = Categories::where('cat_name', $request->cat_name)->first();
        $item = Item::create([
                'title' => $request->title,
                'description' => $request->description,
                'price' => $request->price,
                'quantity' => $request->quantity,
                'SKU' => $request->SKU,
                'image_path' => $this->storeImage($request),
                'cat_id' => (int)$request->cat_id,
                //'cat_id' => $category->cat_id,
             
            ]);
        
        //redirect to items
        return redirect('/items');
    }

    public function show($id){
        return view('items.show', ["item" => Item::findOrFail($id)]);
    }

    //update the database
    public function update(Request $request, $id){
        $item = Item::find($id);
    
        if (!$item) {
            abort(404); 
        }
    
        // Validate the request data
        try {
            $request->validate([
                'title' => 'required|unique:items,title,' . $id . ',id|max:255',
                'cat_id' => 'required|exists:categories,id',
            ]);
    
        } catch (\Illuminate\Validation\ValidationException $e) {
            // redirect back with errors and the previously entered values if validation fails
            return redirect('/items/' . $id . '/edit')
                ->withErrors($e->validator)
                ->withInput();
        }
    
        // update the item if validation passes
        //$category = Categories::where('cat_name', $request->cat_name)->first();
        $item->update([
                'title' => $request->title,
                'description' => $request->description,
                'price' => $request->price,
                'quantity' => $request->quantity,
                'SKU' => $request->SKU,
                //'image_path' => $request->$this->storeImage($request),
                //'cat_id' => $request->cat_id,
                'cat_id' => (int)$request->cat_id,
        ]);
    
        // Redirect to /items/
        return redirect('/items');
        }
    
        //edit the item
        public function edit($id){
        // Retrieve the item by id and pass it to the view
        $item = Item::find($id);
    
        if (!$item) {
            abort(404); 
        }
    
        // Fetch categories
        $categories = Categories::all();

        // Pass both item and categories to the view
        return view('items.edit', ['item' => $item, 'categories' => $categories]);
}

    public function destroy($id) {
        // dd($id); // Uncomment this line to see the ID
        $item = Item::find($id);

        if ($item) {
            $item->delete();
            return redirect()->route('items.index')->with('success', 'Item deleted successfully');
        } else {
            // Handle the case where the item doesn't exist
            abort(404);
        }
        return redirect()->route('items.index')->with('success', 'Item deleted successfully');
    }

    private function storeImage($request){
    if ($request->hasFile('image') && $request->file('image')->isValid()) {
        $newImageName = uniqid() . '-' . $request->title . '.' . $request->image->extension();
        
        $directory = 'uploads';  // Specify your custom path
        $path = $request->image->storeAs($directory, $newImageName, 'public');

        // Return the path for saving in the database
        return $path;
    }

    // Handle the case where the file is not present or not valid
    return null;
}

    // private function storeImage($request){
    //     if ($request->hasFile('image') && $request->file('image')->isValid()) {
    //         $newImageName = uniqid() . '-' . $request->title . '.' . $request->image->extension();
    //         return $request->image->move(public_path('images'), $newImageName);
    //     }
    
    //     // Handle the case where the file is not present or not valid
    //     return null;
    // }
}

