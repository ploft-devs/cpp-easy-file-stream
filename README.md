<div align="center"> 

# Cpp easy file stream
</div>

This is a class for file manipulation done in Cpp. With it, you can easily access a file, and obtain strings and numeric values (integer or decimal) contained within it.

## Usage
To use the class, you need to include it in your file and instantiate it by passing the name of the file you want to use.

```cpp
#include"fs.hpp"
int main(){
    FileStream a ("test.txt");
    return 0;
}
```

## Example

To run the example we have prepared, simply run the following command in the project directory.

```bash
g++ -std=c++17 main.cpp -o example  
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)