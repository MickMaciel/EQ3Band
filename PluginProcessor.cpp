#include "PluginProcessor.h"
#include "PluginEditor.h"

    //==============================================================================
EQ3bandAudioProcessor::EQ3bandAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
#endif
                  ),
parameters(*this, nullptr, "PARAMETERS",
           {
    std::make_unique<juce::AudioParameterFloat>("frequency", "Frequency", juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.3f), 1000.0f),
    std::make_unique<juce::AudioParameterFloat>("gain", "Gain", juce::NormalisableRange<float>(-36.0f, 36.0f, 0.1f, 0.5f), 0.0f)
})
#endif
{
}

EQ3bandAudioProcessor::~EQ3bandAudioProcessor()
{
}

const juce::String EQ3bandAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EQ3bandAudioProcessor::acceptsMidi() const
{
    return false;
}

bool EQ3bandAudioProcessor::producesMidi() const
{
    return false;
}

bool EQ3bandAudioProcessor::isMidiEffect() const
{
    return false;
}

double EQ3bandAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EQ3bandAudioProcessor::getNumPrograms()
{
    return 1;
}

int EQ3bandAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EQ3bandAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String EQ3bandAudioProcessor::getProgramName (int index)
{
    return {};
}

void EQ3bandAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void EQ3bandAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void EQ3bandAudioProcessor::releaseResources()
{
}


void EQ3bandAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    float frequency = *parameters.getRawParameterValue("frequency");
    float gain = *parameters.getRawParameterValue("gain");
    
    for (int channel = 0; channel < getTotalNumOutputChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = channelData[sample] * juce::Decibels::decibelsToGain(gain);
        }
    }
}

bool EQ3bandAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* EQ3bandAudioProcessor::createEditor()
{
    return new EQ3bandAudioProcessorEditor (*this);
}

void EQ3bandAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void EQ3bandAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

