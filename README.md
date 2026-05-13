# Лабораторная работа 7

[![CI](https://github.com/justtavinay-coder/lab07/actions/workflows/cicd.yml/badge.svg)](https://github.com/justtavinay-coder/lab07/actions/workflows/cicd.yml)

В работе настроен CMake-проект с пакетным менеджером Hunter.

## Выполнено

- подключен `HunterGate.cmake`;
- создан собственный CMake-пакет `lab07_solver`;
- пакет добавлен в Hunter и подключается через `hunter_add_package`;
- GTest подключается через Hunter;
- добавлены demo-приложение и тесты.

## Сборка

```sh
cmake -S . -B _build -DBUILD_TESTS=ON
cmake --build _build
cmake --build _build --target test
```

## Запуск demo

```sh
./_build/demo 1 0 -1
```
