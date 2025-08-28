# Practica1-EDD
Primera practica del curso Estructura de datos en el cual se basa en hacer un totito chino
# **README – Instrucciones de Compilación**

Este proyecto implementa un juego de **Puntos y Cuadros** en C++ utilizando **listas enlazadas, pilas y colas**. 
A continuación se presentan los pasos para **compilar el proyecto en Ubuntu (Linux) y en Windows**.

---

## **. Requisitos**

### **Ubuntu**
- Compilador C++ (GCC o Clang)
- [CMake](https://cmake.org/download/)
- (Opcional) CLion para compilación asistida

Instalación rápida:
```bash
sudo apt update
sudo apt install build-essential cmake
```

### **Windows**
- [MinGW-w64](http://mingw-w64.org) (recomendado)
- CLion o Visual Studio Build Tools

---

## **. Compilación en Ubuntu**

1. Abre el proyecto en **CLion**.
2. Selecciona el perfil por defecto (`Debug`).
3. Haz clic en **Build → Build Project**.

Esto generará el ejecutable en:
```
cmake-build-debug/Practica1_EDD
```

### **Compilación manual (sin CLion)**
```bash
mkdir build
cd build
cmake ..
make
```
El ejecutable quedará en `build/Practica1_EDD`.

---

## **. Notas importantes**

- Todos los ejecutables por defecto se generan en la carpeta:
  ```
  cmake-build-debug/
  ```
- Para versiones optimizadas, usa el perfil `Release` en lugar de `Debug`.
- Si necesitas un **ejecutable portable para Windows**, añade la opción de compilación estática:
  ```bash
  x86_64-w64-mingw32-g++ -static -o Practica1_EDD.exe *.cpp
