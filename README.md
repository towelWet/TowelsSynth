# 🎹 Towels Synth 🎵

Welcome to the Towels Synth repository. This is a hands-on project to build an additive synthesizer, a powerful tool that uses multiple sine waves for sound generation.

## 🚀 Steps:

1. Visit the [Audio Programming repository](https://github.com/towelWet/Audio-Programming).
2. Download the necessary components from [Google Drive](https://drive.google.com/drive/folders/1UHS2dEdoqs9llrbmAJpZKOx0uynsae-M?usp=sharing).
3. Now you're ready! Dive into the Towels Synth project and start building.

## 🗂️ Repository Structure

The key elements in this repository are:

1. 🎼 `TowelsSynth.cpp` and `TowelsSynth.h`: Define the `TowelsSynth` class, responsible for sound generation using various parameters.
   
2. 🧠 `PluginProcessor.cpp` and `PluginProcessor.h`: Define the `TowelsSynthAudioProcessor` class, overseeing the audio processing part of the plugin.
   
3. 📋 `PresetListBox.h`: Defines the `PresetListBox` class, responsible for managing a list of presets in your plugin.
   
4. 📐 `magic.xml`: An XML file that employs the Magic GUI library from the `towels_gui_magic` module to layout and style your plugin's GUI.
   
5. 📝 `TowelsSynth.jucer`: The Projucer project file that specifies your project settings.

## 🎚️ GUI Magic

The `towels_gui_magic` module allows the creation of an interactive and visually pleasing interface for adjusting synth parameters. It enables easy addition of sliders, dials, and graphical waveform displays.

To export the audio plugin without the GUI editor for distribution, set `FOLEYS_SHOW_GUI_EDITOR_PALLETTE=0` in JUCE's preprocessor definitions.

---

We're excited to see what you build. If you have any questions or need assistance, feel free to open an issue or submit a pull request. Happy coding!
