# Simple-Pong-Game-with-C-and-raylib
Реализация простой игры понг для двух игроков на базе фреймворка raylib.

## Сборка

Сборка осуществляется с помощью утилиты make для ОС Linux. Предварительно должен быть скомпилирован и установлен сам фреймворк raylib.

### raylib

Для установки необходим компилятор `GCC`, утилита `make` и следующие библиотеки.

```sh
apt install libasound2-dev
apt install libx11-dev
apt install libxrandr-dev
apt install libxi-dev
apt install libgl1-mesa-dev
apt install libglu1-mesa-dev
apt install libxcursor-dev
apt install libxinerama-dev
apt install libwayland-dev
apt install libxkbcommon-dev
```

Затем репозиторий фреймворка клонируется.

```sh
git clone https://github.com/raysan5/raylib.git
```

После клонирования нужно перейти в `raylib/src` и  запустить цель `clean`.

```sh
make clean
```

Скомпилировать фреймворк для десктопа (как статическую библиотеку).

```sh
make PLATFORM=PLATFORM_DESKTOP
```

Созданная библиотека *.a устанавливается в стандартную директорию.

```sh
sudo make install
```