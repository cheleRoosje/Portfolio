<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Models\Categories;

class CategoriesController extends Controller{

    //show categories page
    public function index(){
    $categories = Categories::all();
    return view('categories.index', ['categories' => $categories]);
    }

    //update the database
    public function update(Request $request, $id){
    $category = Categories::find($id);

    if (!$category) {
        abort(404); 
    }

    // Validate the request data
    try {
        $request->validate([
            'cat_name' => 'required|unique:categories,cat_name|max:255',
        ]);

    } catch (\Illuminate\Validation\ValidationException $e) {
        // redirect back with errors and the previously entered values if validation fails
        return redirect('/categories/' . $id . '/edit')
            ->withErrors($e->validator)
            ->withInput();
    }

    // update the category if validation passes
    $category->update([
        'cat_name' => $request->input('cat_name'),
    ]);

    // Redirect to /categories/
    return redirect('/categories');
    }

    //edit the category name
    public function edit($id){
    // Retrieve the category by id and pass it to the view
    $category = Categories::find($id);

    if (!$category) {
        abort(404); 
    }

    return view('categories.edit', ['category' => $category]);
    }

     //creates form
     public function create(){
        return view('categories.create');
    }

    //store a new category in the databse
    public function store(Request $request){

        // Validate the request data
    try {
        $request->validate([
            'cat_name' => 'required|unique:categories,cat_name|max:255',
        ]);

       
        } catch (\Illuminate\Validation\ValidationException $e) {
            // If validation fails, redirect back with errors and the previously entered values
            return redirect('/categories/create')
                ->withErrors($e->validator)
                ->withInput();
        }
        // If validation passes, create a new category
        $category = Categories::create([
            'cat_name' => $request->input('cat_name'),
        ]);
        
        //redirect to categories
        return redirect('/categories');
    }
}
