<?php

namespace Database\Factories;

use App\Models\Item;
use Illuminate\Database\Eloquent\Factories\Factory;
use Illuminate\support\Str;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Item>
 */
class ItemFactory extends Factory
{
    /**
     * Define the model's default state.
     * 
     *
     * @return array<string, mixed>
     */
    protected $model = \App\Models\Item::class;

    public function definition()
    {
        return [
            
            'title' => $this->faker->unique()->word(),
            'description' => $this->faker->sentence(),
            'price' => 2.99,
            'quantity' => 4,
            'SKU' => 10014,
            'image_path' => 'image path',
            'cat_id' => 1
            
        ];
    }
}
