#!/bin/python3

import itertools
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import sys

valid_names = ('Accent', 'Accent_r', 'Blues', 'Blues_r', 'BrBG', 'BrBG_r',
               'BuGn', 'BuGn_r', 'BuPu', 'BuPu_r', 'CMRmap', 'CMRmap_r',
               'Dark2', 'Dark2_r', 'GnBu', 'GnBu_r', 'Greens', 'Greens_r',
               'Greys', 'Greys_r', 'OrRd', 'OrRd_r', 'Oranges', 'Oranges_r',
               'PRGn', 'PRGn_r', 'Paired', 'Paired_r', 'Pastel1', 'Pastel1_r',
               'Pastel2', 'Pastel2_r', 'PiYG', 'PiYG_r', 'PuBu', 'PuBuGn',
               'PuBuGn_r', 'PuBu_r', 'PuOr', 'PuOr_r', 'PuRd', 'PuRd_r',
               'Purples', 'Purples_r', 'RdBu', 'RdBu_r', 'RdGy', 'RdGy_r',
               'RdPu', 'RdPu_r', 'RdYlBu', 'RdYlBu_r', 'RdYlGn', 'RdYlGn_r',
               'Reds', 'Reds_r', 'Set1', 'Set1_r', 'Set2', 'Set2_r', 'Set3',
               'Set3_r', 'Spectral', 'Spectral_r', 'Wistia', 'Wistia_r', 'YlGn',
               'YlGnBu', 'YlGnBu_r', 'YlGn_r', 'YlOrBr', 'YlOrBr_r', 'YlOrRd',
               'YlOrRd_r', 'afmhot', 'afmhot_r', 'autumn', 'autumn_r', 'binary',
               'binary_r', 'bone', 'bone_r', 'brg', 'brg_r', 'bwr', 'bwr_r',
               'cividis', 'cividis_r', 'cool', 'cool_r', 'coolwarm', 'coolwarm_r',
               'copper', 'copper_r', 'cubehelix', 'cubehelix_r', 'flag', 'flag_r',
               'gist_earth', 'gist_earth_r', 'gist_gray', 'gist_gray_r',
               'gist_heat', 'gist_heat_r', 'gist_ncar', 'gist_ncar_r',
               'gist_rainbow', 'gist_rainbow_r', 'gist_stern', 'gist_stern_r',
               'gist_yarg', 'gist_yarg_r', 'gnuplot', 'gnuplot2', 'gnuplot2_r',
               'gnuplot_r', 'gray', 'gray_r', 'hot', 'hot_r', 'hsv', 'hsv_r',
               'inferno', 'inferno_r', 'jet', 'jet_r', 'magma', 'magma_r',
               'nipy_spectral', 'nipy_spectral_r', 'ocean', 'ocean_r', 'pink',
               'pink_r', 'plasma', 'plasma_r', 'prism', 'prism_r', 'rainbow',
               'rainbow_r', 'seismic', 'seismic_r', 'spring', 'spring_r',
               'summer', 'summer_r', 'tab10', 'tab10_r', 'tab20', 'tab20_r',
               'tab20b', 'tab20b_r', 'tab20c', 'tab20c_r', 'terrain',
               'terrain_r', 'turbo', 'turbo_r', 'twilight', 'twilight_r',
               'twilight_shifted', 'twilight_shifted_r', 'viridis', 'viridis_r',
               'winter', 'winter_r')

def grouper(iterable, n, *, incomplete='fill', fillvalue=None):
    """
    Collect data into non-overlapping fixed-length chunks or blocks
    >> grouper('ABCDEFG', 3, fillvalue='x') --> ABC DEF Gxx
    >> grouper('ABCDEFG', 3, incomplete='strict') --> ABC DEF ValueError
    >> grouper('ABCDEFG', 3, incomplete='ignore') --> ABC DEF
    """
    args = [iter(iterable)] * n
    if incomplete == 'fill':
        return itertools.zip_longest(*args, fillvalue=fillvalue)
    if incomplete == 'strict':
        return zip(*args, strict=True)
    if incomplete == 'ignore':
        return zip(*args)
    else:
        raise ValueError('Expected fill, strict, or ignore')

def show_palette_hexcodes(palette):
    cmap = plt.get_cmap(palette)

    print("{")
    for cIDs in grouper(range(cmap.N), 8):
        gen = ((cID, cmap(cID)) if cID is not None else (None,None) for cID in cIDs)
        for cID, rgba in gen:
            if cID is None: break
            hexColor = mpl.colors.rgb2hex(rgba)
            print("    {", f"{cID:3},", hexColor, "},", end="")
        print()
    print("}")

def show_usage():
    print("This tool shows hex colour values for matPlotlib colour palettes.")
    print()
    print("Usage:")
    print(f"   {sys.argv[0]} <palette>")
    print()
    show_palettes()

def show_palettes():
    print("<palette> is one of these:")
    for group in grouper(valid_names, 8):
        print("  ",
              " ".join(f"{name:20}"
                      if name else ""
                      for name in group)
              )

if __name__ == "__main__":
    if len(sys.argv) > 1:
        palette = sys.argv[1]
        if not palette in valid_names:
            print(f"'{palette}' is not a recognized palette name.")
            show_palettes()
        else:
            show_palette_hexcodes(palette)
    else:
        show_usage()
