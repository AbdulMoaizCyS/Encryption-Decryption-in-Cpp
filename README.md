Vader's Caesar Shift Simulator

A menu-driven C++ encryption utility implementing Caesar Cipher-based text encryption and decryption with file handling support.

Features

- Encrypts plaintext messages using Caesar Cipher logic
- Supports uppercase and lowercase alphabet handling
- Handles multi-line text encryption
- Stores encrypted messages in external files
- Reads encrypted text from files and decrypts it
- Menu-driven console interface
- Input validation and file path handling

Technologies Used

- C++
- STL Vectors
- File Handling
- String Manipulation
- ASCII Character Operations

How It Works

The program shifts alphabetical characters using Caesar Cipher encryption logic while preserving character case.

Encrypted text is converted into encoded numerical representations and stored in files. The program can later retrieve the stored encrypted data, parse it, and reconstruct the original plaintext message through decryption logic.

Example Workflow

1. User selects encryption mode
2. User enters one or more lines of text
3. Program encrypts the text
4. User can:
   - Display encrypted text
   - Save encrypted text to a file
5. User can later load the encrypted file for decryption
6. Program reconstructs and displays original plaintext

Compilation

Compile using g++:

g++ main.cpp -o caesar_sim

Run the executable:

./caesar_sim

Future Improvements

- Custom encryption shift values
- Password-protected encryption
- GUI-based interface
- Support for additional cipher algorithms
- Improved encrypted file formatting

Author

Abdul Moaiz