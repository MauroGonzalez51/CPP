#include <bits/stdc++.h>

/**
 *  TODO:
 *      - Encontrar el dato mayor
 *      - Encontrar el dato menor
 *      - Encontrar el numero de intervalos (+30)
 *      - Encontrar la amplitud de cada intervalo :>
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/

void findRange(std::vector <float> &dataVector, float &maxValue, float &minValue, float &rangeValues) {
    maxValue = minValue = dataVector.at(0);

    for (float &data : dataVector) {
        if (data > maxValue) maxValue = data;
        if (data < minValue) minValue = data;
    }
    rangeValues = maxValue - minValue;
}

void findIntervals(int &nIntervals, const int nData) {
    // Usando la regla de Sturges
    float nIntervalsDecimal = (float) (1 + (3.322 * (log10(nData))));
    
    // El numero de intervalos recomendados tiene que ser IMPAR 
    nIntervals = floor(nIntervalsDecimal);
    (nIntervals % 2 == 0) ? nIntervals++ : nIntervals = nIntervals;
}


bool createBreakpoints(std::vector <float> &dataVector, std::vector <float> &breakpoints) {
    bool success = false;
    float maxValue, minValue, rangeValues;
    int nIntervals;

    findRange(dataVector, maxValue, minValue, rangeValues);
    findIntervals(nIntervals, dataVector.size());

    float amplitudeIntervals = rangeValues / nIntervals;
    for (int interval = 0; interval < nIntervals; interval++) 
        breakpoints.push_back((float) (minValue + (amplitudeIntervals * (interval + 1))));
    
    return success;
}