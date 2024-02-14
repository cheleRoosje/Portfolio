<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Inventory Management</title>
    <style type=text/css>
        body {
           font-size: 15px;
           margin: 8px;
           background-color: wheat; 
           text-align: center;
        }
        .container {
            align-content: center;
            position: absolute;
            top: 60%;
            left: 50%;
            transform: translate(-50%, -50%);
            
        }
        .container2 {
            align-content: center;
            position: absolute;
            top: 40%;
            left: 50%;
            transform: translate(-50%, -50%);
            background-color: wheat;
            
        }
        .container-grid-1 {
            background-color: ivory;
            align-content: center;
            justify-content: center;
            width: 500px;
            border-radius: 10px;
            text-align: center;
        }
        .table1{
            text-align: center;
            margin-left:auto; 
            margin-right:auto;

        .active {
            color: #FFC000;
        }
            
        }
     </style>
</head>
<body>
<header>
    <!-- Navigation -->
    <nav class="top-menu-container">
        <div class="logo-header">
            <a href="">
                <img
                src="https://cdn.pixabay.com/photo/2017/02/18/19/20/logo-2078018_960_720.png"
                alt="Logo personal portfolio"
                title="Logo personal portfolio"
                />
            </a>
        </div>

        <ul>
            <li>
                <a href="/categories" class="{{ request()->is("categories") ? 'active' : '' }}">Category List</a>
            </li>
            <li>
                <a href="/items" class="{{ request()->is("items") ? 'active' : '' }}">Item List</a>
            </li>
           
        </ul>
    </nav>
</header>
</body>
@yield('content')
</html>