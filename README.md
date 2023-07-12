# 🎹 Towels Synth 🎵

Welcome to the Towels Synth project - your entry point to creating an additive synthesizer that generates sounds by mixing various sine waves at different frequencies and amplitudes. 

## 🚀 Getting Started

### 💽 Step 1: Fast-Track Access to Required Files

We have consolidated the essential project components, including JUCE, plugin SDKs, and the Towel GUI magic library, into one handy package. 

**Click here to download:** [Google Drive Link](https://drive.google.com/drive/folders/1UHS2dEdoqs9llrbmAJpZKOx0uynsae-M?usp=sharing).

Once downloaded, extract the package. This will reveal two main folders: `2022-JUCE` and `Towel`. Inside the `Towel` folder, navigate to the `PluginGuiMagic` directory, where the Towels Synth project resides in the `examples/TowelsSynth` directory.

💡 The `Build` folder houses the actual release build, and `Builds` is set aside for debugging. Remember, if you're using Xcode, to set it to 'Release' mode. Go to 'Product' in the menu, then 'Scheme', and finally 'Edit Scheme'. Under the 'Run' section in the left panel, you'll find 'Build Configuration'. Set this to 'Release'.

### 📚 Step 2: Unravel the Mystery of What You've Downloaded

**Dive deeper here:** [Audio Programming repository](https://github.com/towelWet/Audio-Programming)

The Audio Programming Folder repo will help you understand Towels Synth more,
as well as the files that Towels Synth relies on.

## 📂 Alternate Download Source: Towels Synth GitHub Repository

While we recommend the Google Drive link for a quick and easy download, you can also find the necessary files in the this repository. 
However, these files are zipped for upload purposes and require extraction:

- [Build.zip](https://github.com/towelWet/TowelsSynth/blob/main/Build.zip)
- [JuceLibraryCode.zip](https://github.com/towelWet/TowelsSynth/blob/main/JuceLibraryCode.zip)
- [modules.zip](https://github.com/towelWet/TowelsSynth/blob/main/modules.zip)

While this method is perfectly viable, the ease of use and pre-packaged nature of the Google Drive link makes it our suggested route for accessing the necessary resources.

## 🗂️ Repository Structure

This repository consists of several crucial elements:

1. 🎼 `TowelsSynth.cpp` and `TowelsSynth.h`: These files define the `TowelsSynth` class, responsible for sound generation using various parameters.
   
2. 🧠 `PluginProcessor.cpp` and `PluginProcessor.h`: These files define the `TowelsSynthAudioProcessor` class, which oversees the audio processing part of the plugin.
   
3. 📋 `PresetListBox.h`: This file defines the `PresetListBox` class, responsible for managing a list of presets in your plugin.
   
4. 📐 `magic.xml`: This XML file uses the Magic GUI library from the `towels_gui_magic` module to layout and style your plugin's GUI.
   
5. 📝 `TowelsSynth.jucer`: This is the Projucer project file that specifies your project settings.

## 🎚️ GUI Magic

The `towels_gui_magic` module empowers the creation of an interactive and aesthetically appealing interface for adjusting synth parameters. It makes the addition of sliders, dials, and graphical waveform displays a breeze.

To export the audio plugin without the GUI editor for distribution, set `FOLEYS_SHOW_GUI_EDITOR_PALLETTE=0` in JUCE's preprocessor definitions.
