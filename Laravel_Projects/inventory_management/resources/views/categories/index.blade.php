@extends('layouts.app')

@section('content')


<div class="container2">
    <div class="container-grid-1">
        <h1>Category List</h1>
    </div>

        <table class="table1" border="10"  style="background-color: ivory; border-color: #DAA520;">
            <thead>
                <tr>
                    <th>Category Name</th>
                    <th>Edit</th>
                </tr>
            </thead>
            <tbody>
                @foreach($categories as $category)
                    <tr>
                        <td>{{ $category->cat_name }}</td>
                        <td>
                            <a href="{{ route('categories.edit', ['id' => $category->id]) }}">Edit</a>
                        </td>

                    </tr>
                @endforeach
            </tbody>
        </table>

        <br/>

        <a href="{{ url('/categories/create') }}">Add a new category</a>
</div>

@endsection
