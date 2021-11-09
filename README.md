# Lucio Engine

In progress, basic cross-plataform 3D game engine.


![Image](https://github.com/joserossini/lucioengine/blob/main/snip.GIF "Sandbox")

---

## Start
First we clone the repository and submodules.
```bach
git clone https://github.com/joserossini/lucioengine.git
git submodule update --init --recursive
```

Then we generate the project files.
For Windows we can use the `build.bat` file to generate VisualStudio project, or you can manually do it.
```bash 
cmake -G "Visual Studio 16 2019" ..
```
Finaly we can work with it.
We can just open VisualStudio. It will take a while to compile for the first time since we are also compiling all the submodules.

---

## Submodules
* sdl2 
* glew 
* gli 
* glm
* nuklear
* std

Updates and Initilize Submodules:
```bash
git submodule update --init --recursive
```
