@extends('layouts.app')

@section('content')

<div class="container2">
    <div class="container-grid-1">
        <h1>Create a New Category</h1>
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

        {{-- <form action="{{ url('/categories') }}" method="post"> --}}
            <form action="{{ route('categories.store') }}" method="post">

            @csrf
            <label for="category">Category Name:</label>
            <input type="text" name="cat_name" value="{{ old('cat_name') }}" />
            <br/>
            <button type="submit">Submit</button>
        </form>

       
    </div>
</div>

@endsection
