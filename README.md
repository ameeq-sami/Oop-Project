To create a `README.md` for your GitHub project, I'll draft a template based on your file structure and typical C++ OOP project conventions. You can further customize it as needed.

---

# Oop-Project

A C++ Object-Oriented Programming project for managing and sorting movies by genre, director, and other attributes. This project demonstrates OOP principles, file handling, and sorting algorithms.

## Features

- **Movie Management:** Add, view, and manage movies of different genres (Action, Animation, Sci-Fi).
- **Director Management:** Store and retrieve director information.
- **Sorting:** Sort movies using Bubble Sort.
- **File Handling:** Read and write movie and director data to text files.
- **OOP Principles:** Uses inheritance, encapsulation, and polymorphism.

## File Structure

```
.
├── actionMovie.cpp/h/txt      # Action movie class and data
├── animationMovie.cpp/h/txt   # Animation movie class and data
├── scifiMovie.cpp/h           # Sci-Fi movie class
├── sicifiMovie.txt            # Sci-Fi movie data
├── director.cpp/h/txt         # Director class and data
├── date.cpp/h                 # Date utility class
├── name.cpp/h                 # Name utility class
├── movie.cpp/h/exe            # Base movie class and executable
├── bubbleSort.cpp/h           # Bubble sort implementation
├── fileHandlingFunc.cpp/h     # File handling utilities
├── main.cpp                   # Main program entry point
├── outputTesing.exe           # Output testing executable
├── testing.cpp                # Additional testing code
```

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- Make (optional, for build automation)

### Build Instructions

To compile the project, run:

```sh
g++ -o movie_program.exe main.cpp actionMovie.cpp animationMovie.cpp scifiMovie.cpp director.cpp date.cpp name.cpp movie.cpp bubbleSort.cpp fileHandlingFunc.cpp
```

Or compile individual components as needed.

### Running

After building, run the executable:

```sh
./movie_program.exe
```

## Usage

- Follow the on-screen prompts to add, view, or sort movies.
- Data is persisted in `.txt` files for each genre and for directors.

## Contributing

Contributions are welcome! Please open issues or submit pull requests for improvements or bug fixes.

## License

This project is licensed under the MIT License.

---

Would you like to add any specific details, such as author information, screenshots, or usage examples? If not, I can create this `README.md` file for you now.
