# 🎹 Towels Synth 🎵

Welcome to the Towels Synth project - your starting point for creating an additive synthesizer, generating sounds by combining various sine waves at different frequencies and amplitudes. 

## 🚀 Getting Started

To successfully work on the Towels Synth project, you'll need access to various audio programming resources. 

### 💽 Step 1: Download Required Files

The necessary components for the project, including JUCE, plugin SDKs, and the Towel GUI magic library, are compiled in one convenient package for you. 

**Download it directly here:** [Google Drive Link](https://drive.google.com/drive/folders/1UHS2dEdoqs9llrbmAJpZKOx0uynsae-M?usp=sharing).

After downloading, extract the package and you'll find two main folders: `2022-JUCE` and `Towel`. Within the `Towel` folder, you'll find the `PluginGuiMagic` folder, and inside this, you'll find the Towels Synth project under the `examples/TowelsSynth` directory.

### 📚 Step 2: Understand What You've Downloaded

Understanding what each component in the package does and how they fit into the broader picture of audio plugin development is essential. 

**For a comprehensive guide, visit the** [Audio Programming repository](https://github.com/towelWet/Audio-Programming). This repository serves as a detailed walkthrough of all the components you've downloaded, providing context and a deeper understanding of their roles in the development of audio plugins. 

After you've downloaded the necessary resources and understood their roles, you're all set to explore the Towels Synth project! Dive into the fascinating world of audio programming and start creating your very own additive synthesizer.

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
