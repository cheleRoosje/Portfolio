<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Item extends Model
{
    use HasFactory;

    protected $primaryKey = 'id';
    protected $fillable = ['title', 'description', 'price', 'quantity', 'SKU', 'image', 'cat_id'];
  

   
}
