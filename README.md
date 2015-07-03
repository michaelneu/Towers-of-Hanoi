# Towers of Hanoi
---

A basic implementation of the towers of hanoi using stacks. Written in plain C. 



### Compiling

Just enter the cloned repository and 
```
$ make
```


### Usage

After compiling the project you simply call `dist/hanoi` with a height. For example: 
```
$ dist/hanoi 2
    =                     
   ===                    
-------------------------
|   A   |   B   |   C   |
-------------------------

                          
   ===      =             
-------------------------
|   A   |   B   |   C   |
-------------------------

                          
            =      ===    
-------------------------
|   A   |   B   |   C   |
-------------------------

                    =     
                   ===    
-------------------------
|   A   |   B   |   C   |
-------------------------
```


### License
The source code is released under the [MIT License](LICENSE.txt). 