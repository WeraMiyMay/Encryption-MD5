# 🇷🇺 Русская версия

# 🔐 MD5‑подобный хешер на C++ Builder

Этот проект — учебная реализация алгоритма, повторяющего ключевые этапы хеш‑функции **MD5**: дополнение сообщения, добавление длины, вычисление констант синуса, раунды преобразований и формирование окончательного 128‑битного хеша.  
Реализация выполнена в **C++ Builder (VCL)**.

---

## ⚙️ Возможности

- ✏️ Ввод строки для хеширования  
- 🧩 Добавление битов дополнения (padding)  
- 🧮 Добавление длины исходного сообщения (64 бита)  
- 🌪 Генерация таблицы констант `T[i] = floor(2³² * |sin(i)|)`  
- 🔄 Выполнение 4 раундов операций MD5‑типа  
- 🧱 Вывод итоговых значений A, B, C, D  
- 🔚 Формирование полного 128‑битного хеша  

---

## 🧠 Кратко о методе

Алгоритм имитирует структуру MD5:

1. 📥 Берём исходную строку и преобразуем её в последовательность байтов  
2. ➕ Добавляем бит `1` (`0x80`)  
3. ➕➕ Дополняем нулями до длины 448 бит по модулю 512  
4. 🔢 Добавляем 64‑битную длину исходного сообщения (little‑endian)  
5. 🌊 Генерируем массив констант синуса  
6. ♻️ Проводим 4 раунда по 16 операций с функциями F, G, H, I  
7. 🎯 Формируем итоговый хеш из регистров A, B, C, D  

⚠️ Реализация **не является криптостойкой** и предназначена только для учебных целей.

---

## ▶️ Как запустить

1. 📥 Склонировать репозиторий  
2. 📦 Открыть проект в **Embarcadero C++ Builder / RAD Studio**  
3. ▶️ Запустить проект (Run → Run)  
4. Ввести строку и нажимать кнопки:  
   - Button1 → Отступ  
   - Button2 → Добавление длины  
   - Button3 → Генерация хеша  
5. Итоговый хеш появится в `Edit5`  

---

## 🎥 Видео‑разбор (TikTok)
 
**https://www.tiktok.com/@alfachonguk2008/video/7426455118964346117?amp%3Bt=1729143153248&q=alphachonguck2008**

---

## 📁 Структура проекта

- `Unit1.cpp` — основная логика  
- `Unit1.h` — заголовочный файл  
- `*.dfm` — UI‑форма  
- Основные компоненты:
  - `Memo1` — исходный текст  
  - `Memo2` — padded сообщение  
  - `Memo3` — сообщение + длина  
  - `Memo5` — таблица T  
  - `Edit1..Edit4` — A, B, C, D  
  - `Edit5` — финальный хеш  

---

# 🇬🇧 English Version

# 🔐 MD5‑Like Hasher in C++ Builder

This project is an educational implementation of an algorithm inspired by the **MD5 hashing process**. It covers message padding, length appending, sinus‑based constant generation, transformation rounds, and final digest construction.  
The project is built using **C++ Builder (VCL)**.

---

## ⚙️ Features

- ✏️ Input string hashing  
- 🧩 MD5‑style message padding  
- 🧮 Appending original message length (64‑bit, little‑endian)  
- 🌪 Generation of T[i] constants using `floor(2³² * |sin(i)|)`  
- 🔄 4 rounds of 16 MD5‑like operations  
- 🧱 Output of registers A, B, C, D  
- 🔚 Final 128‑bit hash generation  

---

## 🧠 Method Overview

The algorithm follows the classic MD5 steps:

1. 📥 Convert input string to bytes  
2. ➕ Append `1` bit (`0x80`)  
3. ➕➕ Pad with zeros until length ≡ 448 (mod 512)  
4. 🔢 Append the original message length (64‑bit LE)  
5. 🌊 Generate sinus‑based constants T[1..64]  
6. ♻️ Perform 4 rounds with F, G, H, I functions  
7. 🎯 Build digest from A, B, C, D registers  

⚠️ This implementation is **not cryptographically secure**. Educational use only.

---

## ▶️ How to Run

1. 📥 Clone the repository  
2. 📦 Open it in **Embarcadero C++ Builder / RAD Studio**  
3. ▶️ Start the project (Run → Run)  
4. Enter text and press:  
   - Button1 → Padding  
   - Button2 → Append length  
   - Button3 → Compute hash  
5. Final digest appears in `Edit5`  

---

## 🎥 Video Explanation (TikTok)

**https://www.tiktok.com/@alfachonguk2008/video/7426455118964346117?amp%3Bt=1729143153248&q=alphachonguck2008**

---

## 📁 Project Structure

- `Unit1.cpp` — main logic  
- `Unit1.h` — header  
- `*.dfm` — UI form  
- Components:
  - `Memo1` — input  
  - `Memo2` — padded message  
  - `Memo3` — message + length  
  - `Memo5` — T constants  
  - `Edit1..Edit4` — A, B, C, D words  
  - `Edit5` — final digest  

---

