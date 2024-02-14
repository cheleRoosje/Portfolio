<?php

use Illuminate\Support\Facades\Route;

use App\Http\Controllers\CategoriesController;

// Resourceful routes
Route::resource('categories', CategoriesController::class)->except(['show']);

// Custom routes
Route::get('/categories/{id}/edit', [CategoriesController::class, 'edit'])->name('categories.edit');
Route::patch('/categories/{id}', [CategoriesController::class, 'update'])->name('categories.update');
Route::delete('/categories/{id}', [CategoriesController::class, 'destroy'])->name('categories.destroy');

use App\Http\Controllers\ItemController;

// Resourceful routes
Route::resource('items', ItemController::class)->except(['show']);
//Route::get('/items', [ItemController::class, 'index']);

Route::get('/items/{id}/edit', [ItemController::class, 'edit'])->name('items.edit');
Route::patch('/items/{id}', [ItemController::class, 'update'])->name('items.update');
Route::delete('/items/{id}', [ItemController::class, 'destroy'])->name('items.destroy');