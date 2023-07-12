/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "TowelsSynth.h"

class PresetListBox;

//==============================================================================
/**
*/
class TowelsSynthAudioProcessor  : public towels::MagicProcessor
{
public:
    //==============================================================================
    TowelsSynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const juce::AudioProcessor::BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================

    //==============================================================================
    void savePresetInternal();
    void loadPresetInternal(int index);

    //==============================================================================
    double getTailLengthSeconds() const override;

private:
    //==============================================================================
    juce::AudioProcessorValueTreeState treeState;

    TowelsSynth      synthesiser;
    juce::ValueTree  presetNode;

    // GUI MAGIC: define that as last member of your AudioProcessor
    towels::MagicLevelSource*   outputMeter  = nullptr;
    towels::MagicPlotSource*    oscilloscope = nullptr;
    towels::MagicPlotSource*    analyser     = nullptr;

    PresetListBox*              presetList   = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TowelsSynthAudioProcessor)
};
