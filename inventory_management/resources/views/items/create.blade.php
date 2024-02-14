@extends('layouts.app')

@section('content')


<div class="container2">
    <div class="container-grid-1">
        <h1>Create a New Item</h1>
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

        
            <form action="{{ route('items.store') }}" method="post" enctype="multipart/form-data">
            {{-- <form action="{{ route('items.create') }}" method="post"> --}}

            @csrf
            <label for="item">Item Name:</label>
            <input type="text" name="title" value="{{ old('title') }}" />
            <br><br>
            <label for="item">Item Description:</label>
            <input type="text" name="description" value="{{ old('description') }}" />
            <br><br>
            <label for="item">Item price:</label>
            <input type="number" min="1" step="any" name="price" value="{{ old('price') }}" />
            <br><br>
            <label for="item">Item Quantity:</label>
            <input type="number" name="quantity" value="{{ old('quantity') }}" />
            <br><br>
            <label for="item">Item SKU:</label>
            <input type="text" name="SKU" value="{{ old('SKU') }}" />
            <br><br>
            <label for="item">Item Image:</label>
            <input type="file" name="image_path" accept="image/*" />
            <br><br>
            <label for="cat_id">Category:</label>
            <select name="cat_id">
                @foreach($categories as $category)
                    <option value="{{ $category->id }}">{{ $category->cat_name }}</option>
                @endforeach
            </select>
            <br><br>

            
            <button type="submit">Add Item</button>
        </form>

    </div>
</div>    


@endsection