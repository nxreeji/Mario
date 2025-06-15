# Platformer Game

## Описание
Platformer Game - это консольная 2D-игра, созданная с использованием библиотеки ncurses. Игрок управляет персонажем (символ 'M'), который перемещается по уровню, собирает монеты ('C'), избегает врагов ('E') и шипов ('^'), чтобы достичь финиша ('+'). Игра поддерживает выбор уровня сложности, физику движения игрока (прыжки, гравитация) и логирование для отладки.

## Основные особенности
- **Управление**:
  - `a` или стрелка влево: движение влево.
  - `d` или стрелка вправо: движение вправо.
  - `w`, пробел или стрелка вверх: прыжок.
  - `s`: зарезервировано для приседания (не реализовано).
  - Esc: пауза или выход.
- **Сложность**: Три уровня (Easy, Medium, Hard), влияющие на количество жизней игрока и скорость врагов.
- **Уровень**: Загружается из файла `map.txt` с символами для стен, монет, шипов, финиша, игрока и врагов.
- **Логирование**: Все действия записываются в `debug.log` для отладки. Логи включают позиции игрока/врагов, столкновения, ввод и ошибки.

## Пример карты
Создайте файл `map.txt` в директории с игрой. Пример:
```
########################
#         C            #
#  M      E       +    #
#                      #
#   S      C           #
########################
```
- `#`: Стена (непроходимая).
- `C`: Монета (+10 очков).
- `+`: Финиш (победа).
- `M`: Начальная позиция игрока.
- `E`: Враг (движется горизонтально).
- `S`: Шипы (отнимают жизнь).
- ` `: Пустое пространство.

## Требования
- **Компилятор**: g++ или любой другой, поддерживающий C++11 или выше.
- **Библиотека ncurses**:
  - Linux: `libncurses5-dev` или `libncursesw5-dev`.
  - macOS: ncurses (обычно предустановлена или через Homebrew).
  - Windows: PDCurses (рекомендуется) или ncurses через WSL/Cygwin.
- **Утилита make**: Опционально, для упрощения сборки.
- **Файл карты**: `map.txt` в директории с исполняемым файлом.

## Установка

### Linux (Ubuntu/Debian)
1. Установите необходимые зависимости:
   ```bash
   sudo apt-get update
   sudo apt-get install g++ libncurses5-dev libncursesw5-dev
   ```
2. Склонируйте или распакуйте проект в любую директорию:
   ```bash
   git clone <repository_url>  # Если проект в репозитории
   cd platformer-game
   ```
3. Создайте файл `map.txt` (пример см. ниже).

### macOS
1. Установите Homebrew, если он не установлен:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
2. Установите g++ (входит в Xcode Command Line Tools) и ncurses:
   ```bash
   xcode-select --install
   brew install ncurses
   ```
3. Склонируйте или распакуйте проект:
   ```bash
   git clone <repository_url>
   cd platformer-game
   ```
4. Создайте файл `map.txt`.

### Windows
На Windows ncurses не поддерживается нативно, поэтому рекомендуется использовать PDCurses или Windows Subsystem for Linux (WSL).

#### Вариант 1: PDCurses (рекомендуется)
1. Установите MinGW (например, через MSYS2):
   ```bash
   # Установите MSYS2 с https://www.msys2.org/
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-pdcurses
   ```
2. Склонируйте или распакуйте проект в директорию.
3. Создайте файл `map.txt`.

#### Вариант 2: WSL
1. Установите WSL2 и дистрибутив Ubuntu:
   ```powershell
   wsl --install
   ```
2. В WSL установите зависимости, как для Linux:
   ```bash
   sudo apt-get update
   sudo apt-get install g++ libncurses5-dev libncursesw5-dev
   ```
3. Склонируйте или распакуйте проект в WSL.
4. Создайте файл `map.txt`.

## Сборка
1. Перейдите в директорию проекта:
   ```bash
   cd path/to/platformer-game
   ```
2. Скомпилируйте проект:
   - **Linux/macOS**:
     ```bash
     g++ -o platformer main.cpp Game.cpp Level.cpp Player.cpp Enemy.cpp MainMenu.cpp Utils.cpp -lncurses
     ```
   - **Windows (PDCurses)**:
     ```bash
     g++ -o platformer main.cpp Game.cpp Level.cpp Player.cpp Enemy.cpp MainMenu.cpp Utils.cpp -lpdcurses
     ```
   - **WSL**: Используйте команду для Linux.
3. (Опционально) Создайте Makefile для упрощения:
   ```makefile
   all:
       g++ -o platformer main.cpp Game.cpp Level.cpp Player.cpp Enemy.cpp MainMenu.cpp Utils.cpp -lncurses
   clean:
       rm -f platformer debug.log
   ```
   Затем выполните:
   ```bash
   make
   ```

## Запуск
1. Убедитесь, что `map.txt` существует в директории с исполняемым файлом.
2. Запустите игру:
   ```bash
   ./platformer
   ```
3. В главном меню используйте стрелки вверх/вниз для навигации и Enter для выбора:
   - **Start Game**: Начать игру.
   - **Select Difficulty**: Выбрать сложность (Easy, Medium, Hard).
   - **Exit**: Выйти.

## Известные проблемы
- Пауза (Esc) не позволяет возобновить игру.
- Клавиша `s` логируется, но не реализована.
- Движение игрока может "залипать" при отпускании клавиш.

## Планы на улучшение
- Добавить полноценную паузу с возобновлением.
- Реализовать приседание для `s`.
- Добавить перезапуск уровня после смерти/победы.
- Оптимизировать рендеринг.

## Зависимости
- **ncurses** (Linux/macOS) или **PDCurses** (Windows): Для консольного интерфейса.
- **C++ Standard Library**: Для файлов, строк и контейнеров.

## Автор
nxreeji