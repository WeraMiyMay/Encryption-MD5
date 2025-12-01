
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
