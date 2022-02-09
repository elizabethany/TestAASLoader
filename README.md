# Doom 2016 AAS Loader

A program that reads a binary AAS file (`.baas`) and loads it into a struct. Currently, said data is then written out to a text AAS file (`.aas`).

Majority of the code was written by chrispy, and I take no credit for any of it.

## Usage
Run program and enter path to `.baas` file. Alternatively, drag and drop the `.baas` on to the executable. A `.aas` file will written to the `Output` folder.

## Potential Issues
Two `.aas` files exist for Doom 2016, so those plus the Doom 3 BFG writer were used as reference for this program's text AAS writer. But due to the limited sample size, and that the D3BFG writer is not the latest implementation, a few of the fields might have their values written out in the wrong order.

Items such as portals, portalIndex, hintNodes, and trees, have one or zero entries, so while they look right, I can't confirm that they are being written out correctly.

Other items such as areas and traversalPoints, contain a lot of values, which based on the two `.aas` files, are not simply written out in the order they appear in the struct, nor is there any reference in the D3BFG writer.

Other items with noting, but shouldn't be problematic, include:
* Some values are written out in scientific notation; I'm not sure if the game accepts values in this format for `.aas` files (it should for `.entities`)
* AAS file ID and version are just harcoded, and not derived from anything (D3BFG writer does this too)
* No idea what the 0 value right after is
* `type` is a numerical value of some sort, so its string value is derived from the `idAAS2Settings::type_t` enum
* Some values are unsigned char that were cast to int to display properly
