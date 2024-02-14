@extends('layouts.app')

@section('content')


<div class="container2">
    <div class="container-grid-1">
        <h1>Edit an Item</h1>
    </div>
    <div class="container-grid-1">
        @if ($errors->any())
            <div style="color: red;">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif

        <form action="{{ route('items.update', ['id' => $item->id]) }}" method="post">

            {{-- <form action="{{ route('/categories/' . $category->id) }}" method="post"> --}}
            @csrf
            @method('PATCH') <!-- Use this to set the HTTP method to PATCH -->
            
            <label for="item">Item Name:</label>
            <input type="text" name="title" value="{{ old('title', $item->title) }}" />
            <br><br>
            <label for="item">Item Description:</label>
            <input type="text" name="description" value="{{ old('description', $item->description) }}" />
            <br><br>
            <label for="item">Item price:</label>
            <input type="number" min="1" step="any" name="price" value="{{ old('price', $item->price) }}" />
            <br><br>
            <label for="item">Item Quantity:</label>
            <input type="number" name="quantity" value="{{ old('quantity', $item->quantity) }}" />
            <br><br>
            <label for="item">Item SKU:</label>
            <input type="text" name="SKU" value="{{ old('SKU', $item->SKU) }}" />
            <br><br>
            <label for="item">Item Image:</label>
            <input type="text" name="image_path" value="{{ old('image_path', $item->image_path) }}" />
            <br><br>
            <label for="cat_id">Category:</label>
            <select name="cat_id">
                @foreach($categories as $category)
                <option value="{{ $category->id }}" @if(old('cat_id', $item->cat_id) == $category->id) selected @endif>{{ $category->cat_name }}</option>
                @endforeach
            </select>
            <br><br>


            <button type="submit">Update Item</button>
        </form>
    </div>
</div>


@endsection