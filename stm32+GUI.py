from tkinter import *
from tkinter import ttk
import serial
import pygame

# --- Setup Serial Communication ---
try:
    ser = serial.Serial("COM3", 9600, timeout=1)  # replace COM3 with your STM32 port
except Exception as e:
    print("⚠ Could not open serial port:", e)
    ser = None  # GUI will still work even if serial is disconnected

# --- Functions to send commands ---
def send_display_image():
    if ser:
        ser.write(b'I')
        print("IMG\n")
    else:
        print("Serial not connected")

def send_led_matrix():
    if ser:
        ser.write(b'L')
        print("LED\n")
    else:
        print("Serial not connected")

def play_sound():
    if ser:
        ser.write(b'P')
        print("PLAY\n")
    else:
        print("Serial not connected")

def pause_sound():
    if ser:
        ser.write(b'U')
        print("PAUSE\n")
    else:
        print("Serial not connected")

def stop_sound():
    if ser:
        ser.write(b'S')
        print("STOP\n")
    else:
        print("Serial not connected")
def equalizer():
    if ser:
        ser.write(b'E')
        print("EQUALIZER ON\n")
    else:
        print("Serial not connected")

# --- Main Window ---
root = Tk()
root.title("STM32 Controller")
root.geometry("420x400")
root.configure(bg="#ECF0F1")

# --- Style ---
style = ttk.Style()
style.theme_use("clam")
style.configure("TButton",
                font=("Segoe UI", 13, "bold"),
                padding=10,
                relief="flat",
                foreground="#ffffff",
                background="#2980B9")  # Darker blue buttons
style.map("TButton",
          background=[("active", "#1F618D")],  # Hover effect
          foreground=[("active", "#ffffff")])

# --- Title ---
title = Label(root,
              text="Desktop GUI",
              font=("Segoe UI", 20, "bold"),
              bg="#ECF0F1", fg="#1F618D")
title.pack(pady=20)

# --- Buttons stacked vertically ---
btn_img = ttk.Button(root, text="🖼 IMAGE", width=15, command=send_display_image)
btn_img.pack(pady=10)

btn_led = ttk.Button(root, text="💡 LED MATRIX", width=15, command=send_led_matrix)
btn_led.pack(pady=10)

# --- Sound row (Play, Pause, Stop) ---
sound_frame = Frame(root, bg="#ECF0F1")
sound_frame.pack(pady=10)

btn_play = ttk.Button(sound_frame, text="▶", width=4, command=play_sound)
btn_play.grid(row=0, column=0, padx=5)

btn_pause = ttk.Button(sound_frame, text="⏸", width=4, command=pause_sound)
btn_pause.grid(row=0, column=1, padx=5)

btn_stop = ttk.Button(sound_frame, text="⏹", width=4, command=stop_sound)
btn_stop.grid(row=0, column=2, padx=5)

# --- Quit Button ---
quit_btn = ttk.Button(root, text="Quit", command=root.destroy, width=15)
quit_btn.pack(pady=20)

root.mainloop()
