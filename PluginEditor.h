/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class EQ3bandAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     public juce::Slider::Listener
{
public:
    EQ3bandAudioProcessorEditor (EQ3bandAudioProcessor&);
    ~EQ3bandAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    // Implementação do método listener para sliders
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    EQ3bandAudioProcessor& audioProcessor;
    
    //Sliders
    juce::Slider frequencySlider;
    juce::Slider gainSlider;
    
    // Attachments para conectar sliders aos parâmetros
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> frequencyAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;

    //Labels
    juce::Label frequencyLabel;
    juce::Label gainLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQ3bandAudioProcessorEditor)
};
