/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PresetListBox.h"

//==============================================================================

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    TowelsSynth::addADSRParameters (layout);
    TowelsSynth::addOvertoneParameters (layout);
    TowelsSynth::addGainParameters (layout);
    return layout;
}

//==============================================================================

TowelsSynthAudioProcessor::TowelsSynthAudioProcessor()
  : towels::MagicProcessor (juce::AudioProcessor::BusesProperties()
                            .withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
    treeState (*this, nullptr, ProjectInfo::projectName, createParameterLayout())
{
    TOWELS_SET_SOURCE_PATH (__FILE__);

    auto file = juce::File::getSpecialLocation (juce::File::currentApplicationFile)
        .getChildFile ("Contents")
        .getChildFile ("Resources")
        .getChildFile ("magic.xml");

    if (file.existsAsFile())
        magicState.setGuiValueTree (file);
    else
        magicState.setGuiValueTree (BinaryData::magic_xml, BinaryData::magic_xmlSize);

    // MAGIC GUI: add a meter at the output
    outputMeter  = magicState.createAndAddObject<towels::MagicLevelSource>("output");
    oscilloscope = magicState.createAndAddObject<towels::MagicOscilloscope>("waveform");

    analyser     = magicState.createAndAddObject<towels::MagicAnalyser>("analyser");
    magicState.addBackgroundProcessing (analyser);

    presetList = magicState.createAndAddObject<PresetListBox>("presets");
    presetList->onSelectionChanged = [&](int number)
    {
        loadPresetInternal (number);
    };
    magicState.addTrigger ("save-preset", [this]
    {
        savePresetInternal();
    });

    magicState.setApplicationSettingsFile (juce::File::getSpecialLocation (juce::File::userApplicationDataDirectory)
                                           .getChildFile (ProjectInfo::companyName)
                                           .getChildFile (ProjectInfo::projectName + juce::String (".settings")));

    magicState.setPlayheadUpdateFrequency (30);

    
    // next 2 lines were added for sound
//    presetNode = magicState.getSettings().getOrCreateChildWithName ("presets", nullptr);
//   presetNode.setProperty ("foo", 100, nullptr);
    
    TowelsSynth::TowelsSound::Ptr sound (new TowelsSynth::TowelsSound (treeState));
    synthesiser.addSound (sound);

    for (int i=0; i < 16; ++i)
        synthesiser.addVoice (new TowelsSynth::TowelsVoice (treeState));
}

//==============================================================================
void TowelsSynthAudioProcessor::prepareToPlay (double sampleRate, int blockSize)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synthesiser.setCurrentPlaybackSampleRate (sampleRate);

    // MAGIC GUI: setup the output meter
    outputMeter->setupSource (getTotalNumOutputChannels(), sampleRate, 500);
    oscilloscope->prepareToPlay (sampleRate, blockSize);
    analyser->prepareToPlay (sampleRate, blockSize);
}

void TowelsSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool TowelsSynthAudioProcessor::isBusesLayoutSupported (const juce::AudioProcessor::BusesLayout& layouts) const
{
    // This synth only supports mono or stereo.
    return (layouts.getMainOutputChannelSet() == juce::AudioChannelSet::mono()
            || layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo());
}

void TowelsSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    
    
    //next 2 lines are new
 //   auto totalNumInputChannels = getTotalNumInputChannels();
 //   auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    
    // MAGIC GUI: send midi messages to the keyboard state and MidiLearn
    magicState.processMidiBuffer (midiMessages, buffer.getNumSamples(), true);

    // MAGIC GUI: send playhead information to the GUI
    magicState.updatePlayheadInformation (getPlayHead());

    synthesiser.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());

    for (int i = 1; i < buffer.getNumChannels(); ++i)
        buffer.copyFrom (i, 0, buffer.getReadPointer (0), buffer.getNumSamples());

    // MAGIC GUI: send the finished buffer to the level meter
    outputMeter->pushSamples (buffer);
    oscilloscope->pushSamples (buffer);
    analyser->pushSamples (buffer);
}

//==============================================================================
void TowelsSynthAudioProcessor::savePresetInternal()
{
    presetNode = magicState.getSettings().getOrCreateChildWithName ("presets", nullptr);

    juce::ValueTree preset { "Preset" };
    preset.setProperty ("name", "Preset " + juce::String (presetNode.getNumChildren() + 1), nullptr);

    towels::ParameterManager manager (*this);
    manager.saveParameterValues (preset);

    presetNode.appendChild (preset, nullptr);
}

void TowelsSynthAudioProcessor::loadPresetInternal(int index)
{
    presetNode = magicState.getSettings().getOrCreateChildWithName ("presets", nullptr);
    auto preset = presetNode.getChild (index);

    towels::ParameterManager manager (*this);
    manager.loadParameterValues (preset);
}

//==============================================================================

double TowelsSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TowelsSynthAudioProcessor();
}
