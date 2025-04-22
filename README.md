# 🛒 Electronic Shop Management System

A console-based **C++ application** designed to help small electronics shops manage their inventory, billing, and daily operations efficiently. This system supports item management (add/update/delete), sales processing, and persistent storage using binary files—all wrapped in a password-protected interface.

---

## 📌 Table of Contents

- [Features](#-features)
- [Demo](#-demo)
- [Getting Started](#-getting-started)
- [Login Credentials](#-login-credentials)
- [How It Works](#-how-it-works)
- [Code Structure](#-code-structure)
- [Technologies Used](#-technologies-used)
- [Limitations](#-limitations)
- [Contributing](#-contributing)
- [Author](#-author)
- [License](#-license)

---

## ✨ Features

- 🔐 **Password Protected Access**
- ➕ Add new electronic items
- 📋 Display all items in inventory
- 🔍 Search items by name
- ✏️ Update item details (name, price, quantity)
- ❌ Delete item from inventory
- 🧾 Generate customer bills based on purchases
- 💾 Persistent storage using file I/O (binary format)
- 🧠 Simple and intuitive menu-driven interface

---

## 🎬 Demo Menu

When you run the program successfully and log in, you'll see a menu like this:

```text
1. Add Item
2. Show All Items
3. Search Item
4. Delete Item
5. Update Item
6. Generate Bill
7. Exit
```


---

## 🚀 Getting Started

### 🧱 Prerequisites

- C++ compiler (e.g., `g++`)
- Terminal or Command Prompt

### 🔧 Installation & Usage

1. **Clone this repository or download the file** `Electronic_Shop.cpp`.

2. **Open terminal and compile the source code**:

```
g++ Electronic_Shop.cpp -o ElectronicShop
```
Run the compiled program:

```bash
./ElectronicShop
```
---

## 🔐 Login Credentials

To prevent unauthorized access, the system requires authentication.

- **Username:** `admin`  
- **Password:** `123`

> You can customize these credentials directly in the source code.

---

## ⚙️ How It Works

### 📦 Item Structure

Each item stored includes:

- `Item Code`: A unique identifier
- `Item Name`: Name of the electronic product
- `Price`: Price per unit
- `Quantity`: Quantity available

These are stored in a binary file (`itemstore.dat`) for persistence.

### 💵 Billing Process

- User is prompted to input item name and quantity
- If available, total cost is calculated and shown
- Final bill with itemized breakdown is displayed

---

## 🗂 Code Structure

| Section             | Description |
|---------------------|-------------|
| `main()`            | Entry point with login & menu loop |
| `class item`        | Contains item data and methods like `add()`, `show()`, `search()`, etc. |
| File operations     | Binary file handling for saving and retrieving item data |
| Authentication      | Basic user login system with validation |
| UI elements         | Text-based menu system and status messages |

---

## 🛠 Technologies Used

- **Language**: C++
- **File I/O**: Binary file handling (`fstream`)
- **Data Handling**: Classes and objects
- **Interface**: Console/Terminal

---

## ⚠️ Limitations

- Not cross-platform GUI — terminal only
- Passwords stored in plain text
- No input validation or error recovery for file corruption
- No database integration

---

## 🤝 Contributing

Pull requests are welcome! If you have suggestions for improvements:

1. Fork the repository  
2. Create your branch (`git checkout -b feature-branch`)  
3. Commit your changes (`git commit -m 'Add new feature'`)  
4. Push to the branch (`git push origin feature-branch`)  
5. Open a pull request

---

## 👨‍💻 Author

Developed by [**Aabhas Mishra**](https://github.com/Aabhasmishra)

---

## 📄 License

This project is open-source and free to use for educational or learning purposes.
