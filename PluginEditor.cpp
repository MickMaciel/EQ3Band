/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

    //==============================================================================
EQ3bandAudioProcessorEditor::EQ3bandAudioProcessorEditor (EQ3bandAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p)
{
        // Configuração do slider de frequência
    frequencySlider.setSliderStyle(juce::Slider::Rotary); // Define o estilo do slider como rotativo
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20); // Define a caixa de texto abaixo do slider
    addAndMakeVisible(frequencySlider); // Torna o slider visível na interface
    
        // Configuração do rótulo de frequência
    frequencyLabel.setText("Frequency (Hz)", juce::dontSendNotification); // Define o texto do rótulo
    frequencyLabel.attachToComponent(&frequencySlider, false); // Anexa o rótulo ao slider
    addAndMakeVisible(frequencyLabel); // Torna o rótulo visível na interface
    
        // Configuração do slider de ganho
    gainSlider.setSliderStyle(juce::Slider::Rotary); // Define o estilo do slider como rotativo
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20); // Define a caixa de texto abaixo do slider
    addAndMakeVisible(gainSlider); // Torna o slider visível na interface
    
        // Configuração do rótulo de ganho
    gainLabel.setText("Gain (dB)", juce::dontSendNotification); // Define o texto do rótulo
    gainLabel.attachToComponent(&gainSlider, false); // Anexa o rótulo ao slider
    addAndMakeVisible(gainLabel); // Torna o rótulo visível na interface
    
        // Attachments para conectar sliders aos parâmetros
    frequencyAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.parameters, "frequency", frequencySlider);
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.parameters, "gain", gainSlider);
    
        // Define o tamanho da interface do plugin
    setSize(400, 300);
}

EQ3bandAudioProcessorEditor::~EQ3bandAudioProcessorEditor()
{
}

    //==============================================================================
void EQ3bandAudioProcessorEditor::paint (juce::Graphics& g)
{
        // Preenche o fundo com a cor de fundo da janela redimensionável
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
        // Define a cor e a fonte do texto
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
        // Desenha o texto centralizado
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void EQ3bandAudioProcessorEditor::resized()
{
        // Define as posições dos sliders e rótulos
    frequencySlider.setBounds(50, 50, 100, 100);
    gainSlider.setBounds(200, 50, 100, 100);
}
