@extends('layouts.app')

@section('content')


<div class="container">
    <div class="container-grid-1">

    <h1>Item List</h1>

    <a href="{{ url('/items/create') }}">Add a new item</a>
    <br/><br/><br/>
    </div>
    <br/><br/>

    <div class="container-grid-2">

    <table class="table1" border="10"  style="background-color: ivory; border-color: #DAA520;">
        <thead>
            <tr>
                <th>Item Title</th>
                <th>Edit</th>
                <th>Delete</th>
            </tr>
        </thead>
        <tbody>
            @foreach($items as $item)
                <tr>
                    <td>{{ $item->title }}</td>
                    <td>
                        <a href="{{ route('items.edit', ['id' => $item->id]) }}">Edit</a>
                    </td>
                    <td>
                        {{-- <form action="{{ route('items.destroy',['id' => $item->id]) }}" method="post"> --}}
                        {{-- <a href="{{ route('items.destroy', ['id' => $item->id]) }}" onclick="return confirm('Are you sure?')">Delete</a> --}}
                        <form action="{{ route('items.destroy', $item->id) }}" method="post">
                            @csrf
                            @method('DELETE')
                            <button type="submit">Delete</button>
                        </form>
                    </td>

                </tr>
            @endforeach
        </tbody>
    </table>

    </div>

</div>
    <br/>
    

@endsection
