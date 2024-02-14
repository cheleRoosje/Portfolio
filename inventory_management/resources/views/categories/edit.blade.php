@extends('layouts.app')

@section('content')


<div class="container2">
    <div class="container-grid-1">
        <h1>Edit Category</h1>
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

        <form action="{{ $category->id ? route('categories.update', ['id' => $category->id]) : '#' }}" method="post">

            {{-- <form action="{{ route('/categories/' . $category->id) }}" method="post"> --}}
            @csrf
            @method('PATCH') <!-- Use this to set the HTTP method to PATCH -->
            
            <label for="cat_name">Category Name:</label>
            <input type="text" name="cat_name" value="{{ old('cat_name', $category->cat_name) }}" />
            <!-- old('cat_name', $category->cat_name) will pre-fill the input with the existing category name -->

            <br/>
            <button type="submit">Update Category</button>
        </form>
    </div>
</div>

@endsection



