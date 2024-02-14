<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('items', function (Blueprint $table) {
            $table->increments("id");
            $table->string('title');
            $table->string('description');
            $table->decimal('price', 10, 2);
            $table->integer('quantity');
            $table->string('SKU', 20);
            $table->string('image_path')->nullable();//store file path
            $table->unsignedInteger('cat_id');
            $table->foreign('cat_id')->references('id')->on('categories');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('items');
    }
};
