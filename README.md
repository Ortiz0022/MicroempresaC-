# Stock Management System for Microbusinesses

This C++ project is a console-based application that allows small businesses to manage their products, stock, sales, customer orders, and user roles (administrator and client). It is designed with object-oriented programming principles and a simple text interface.

## Key Features

- Administrator and client user roles.
- Admin registration and login with a predefined password.
- Clients can register, view the product catalog, and place orders.
- Randomly generated customer codes.
- Stock management: add, remove, and update product quantities.
- Sales tracking with automatic total calculation.
- Reusable message prompts for consistent user experience.

## Class Structure

- `Persona`: Base class inherited by `Administrator` and `Client`.
- `Administrator`: Manages product stock and sales.
- `Client`: Can place orders and view products.
- `Articulo`: Represents a product in stock.
- `Pedidos`: Inherits from `Articulo`, represents a customer order.
- `Ventas`: Records product sales and calculates revenue.
- `Reutilizados`: Contains reusable messages for user interaction.

## Authors

This project was developed collaboratively by:

- **Angélica Ortiz Barrantes**
- **Greilyn Esquivel Salazar**
- **Katheryn Méndez Quirós**
- **Krystel Salazar Chavarría**
  
As part of a C++ programming course focused on object-oriented design.
