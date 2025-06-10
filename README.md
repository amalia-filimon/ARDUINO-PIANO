# Arduino Piano

This Arduino project implements a digital piano using **10 push buttons**, a **buzzer**, and an **Arduino Uno** board. The system allows the user to play 8 different musical notes and includes functionality to **record** and **play back** a custom melody using hardware interrupts.

---

## 🛠️ Hardware Components

- 1 × Arduino Uno  
- 8 × Push buttons for musical notes  
- 1 × Push button for **recording**  
- 1 × Push button for **playback**  
- 1 × Buzzer / speaker  
- Jumper wires  
- Breadboard  
- USB cable

---

## 🧠 Features

- 🎵 Play 8 different musical notes
- 🎙️ Record the sequence of notes using an external interrupt (button on pin 2)
- 🔁 Playback the recorded melody using another button (pin 3)
- 🎚️ Debounce handling for stable input
- 🎶 Tone generation using `tone()` function
- ⏱️ Uses `millis()` for debounce timing
- 👂 Melodies stored in a buffer (`melody[]`) during recording

---

## 📁 File Structure

| File            | Description                                       |
|------------------|---------------------------------------------------|
| `Arduino_Piano.ino`  | Main implementation                          |
| `pitches.h`      | Header defining frequencies for musical notes    |

---

## 🎹 Button Mapping

| Function     | Pin  | Note         |
|--------------|------|--------------|
| Play Note 1  | 4    | NOTE_A7      |
| Play Note 2  | 5    | NOTE_AS7     |
| Play Note 3  | 6    | NOTE_B7      |
| Play Note 4  | 7    | NOTE_C8      |
| Play Note 5  | 9    | NOTE_CS8     |
| Play Note 6  | 10   | NOTE_D8      |
| Play Note 7  | 11   | NOTE_DS8     |
| Play Note 8  | 12   | NOTE_GS7     |
| Record       | 2    | Toggle record mode (start/stop) |
| Playback     | 3    | Play recorded melody            |

---

## 🧾 Notes

- The speaker is connected to pin `8` and plays tones using the `tone()` function.
- Melody is stored in a `melody[100]` array and played back with fixed timing.
- Interrupts ensure accurate real-time response for button presses.

---
