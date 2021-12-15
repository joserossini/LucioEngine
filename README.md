# Lucio Engine

In progress, basic cross-plataform 3D graphics engine.

---

## Building project files
First we clone the repository and submodules.
```bach
git clone git@github.com:joserossini/lucio.git
git submodule update --init --recursive
```

Then we generate the project files.
For Windows we can use the `build.bat` file to generate VisualStudio project, or you can manually do it.
```bash 
cmake -G "Visual Studio 17 2022" ..
```
Finaly we can work with it.
We can just open VisualStudio. It will take a while to compile for the first time since we are also compiling all the submodules.

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
