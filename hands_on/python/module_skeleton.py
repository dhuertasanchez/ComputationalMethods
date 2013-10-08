import numpy as np

"""
Module with all the functions to process sismographic data.
Authors: Jaime E. Forero-Romero
Creation date: Tue Oct  8 11:48:53 COT 2013
"""

def load_data(filename):
    """
    Loads sismographic data from an ascii file.

    Input: filename.
    Output: numpy array with all the data.
    """

    n = 10;
    m = 100;
    data = np.ones((n,m))
    return data

def get_fft_raw(data):
    """
    Uses raw data to compute the power spectrum.
    Input: 
    - data: numpy array of shape [n:m]. Raw data.   
    Output:
    - fft_freq: numpy array of shape [n,m]. Frequencies for each signal.
    - fft_amplitides: numpy complex array of shape[n,m]. Fourier amplitudes.
    """
    
    fft_amplitudes = data
    fft_freq = data
    return fft_freq, fft_amplitudes

def get_p_spectrum(fft_freq, fft_amplitudes):
    """
    Computes the power spectrum from fft data.

    Input: 
    - fft_freq: numpy array of shape [n,m]. Frequencies for each signal.
    - fft_amplitides: numpy complex array of shape[n,m]. Fourier amplitudes.
    Output:
    - p_spectrum: numpy array of shape [n,m]. Power spectrum for each signal.
    n runs over the signals
    m runs over the frequencies
    """
    #computes the power spectrum
    p_spectrum = fft_amplitudes;

    return p_spectrum


def make_plots(fft_freq, p_spectrum):
    """
    Makes power spectrum plots.

    Input: 
    - fft_freq: numpy array of shape [n,m]. Frequencies for each signal.
    - p_spectrum: numpy array of shape [n,m]. Power spectrum for each signal.
    n runs over the signals
    m runs over the frequencies
    """
    return
