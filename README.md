# 🎹 Towels Synth 🎵

Welcome to the Towels Synth project - your gateway to creating an additive synthesizer, which generates sounds by combining various sine waves at different frequencies and amplitudes. 

## 🚀 Getting Started

To successfully navigate the Towels Synth project, you'll need access to several audio programming resources. 

### 💽 Step 1: Download and Extract Required Files

The necessary components for the project, including JUCE, plugin SDKs, and the Towel GUI magic library, are compiled in one convenient package for you. 

**Download it directly here:** [Google Drive Link](https://drive.google.com/drive/folders/1UHS2dEdoqs9llrbmAJpZKOx0uynsae-M?usp=sharing).

After downloading, extract the package. You'll find two primary folders: `2022-JUCE` and `Towel`. Within the `Towel` folder, locate the `PluginGuiMagic` folder. Inside this, you'll find the Towels Synth project in the `examples/TowelsSynth` directory.

In the Towels Synth GitHub repository, you'll find the following zip files:

- [Build.zip](https://github.com/towelWet/TowelsSynth/blob/main/Build.zip)
- [JuceLibraryCode.zip](https://github.com/towelWet/TowelsSynth/blob/main/JuceLibraryCode.zip)
- [modules.zip](https://github.com/towelWet/TowelsSynth/blob/main/modules.zip)

These files were zipped for upload purposes and need to be extracted. The `Build` folder is for the actual release build, while `Builds` is for debugging.

If you're using Xcode, ensure that it is set to 'Release'. You can do this by selecting 'Product' from the menu, then 'Scheme', and finally 'Edit Scheme'. In the left panel, under the 'Run' section, you'll find 'Build Configuration'. Make sure it's set to 'Release'.

### 📚 Step 2: Understand What You've Downloaded

The components in the package are part of a bigger picture in audio plugin development, and understanding their roles is vital. 

**Visit the** [Audio Programming repository](https://github.com/towelWet/Audio-Programming) for a detailed walkthrough. This repository explains the roles and functions of the components you've downloaded.

With the necessary resources downloaded, understood, and set up, you're ready to dive into the Towels Synth project! Explore the world of audio programming and start creating your very own additive synthesizer.

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
