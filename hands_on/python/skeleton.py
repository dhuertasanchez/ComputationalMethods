import module_skeleton as ms



def main():
    """
    Reads sismographic data to make a power spectrum analysis.
    """
    
    #defines input/output files
    inputfile='in.dat'
    outputdile='out.dat'
    figure_name='pp_figures'

    #loads the data
    data = ms.load_data(inputfile)

    #gets the FFT spectrum and the frequencies
    fft_raw, fft_freq = ms.get_fft_raw(data)
    
    #computes the power spectrum
    p_spectrum = ms.get_p_spectrum(fft_raw, fft_freq)

    #makes all plots:
    ms.make_plots(p_spectrum, fft_freq)


if __name__ == "__main__":
    main()
