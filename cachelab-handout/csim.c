#include "cachelab.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <getopt.h>
typedef unsigned long long int address;

struct cacheDef {
    int s;
    int S;
    int E;
    int b;
    int hits;
    int misses;
    int evictions;
};

struct line {
int latest;
int valid;
address tag;
};

struct set {
    struct line *lines;
};

struct cache {
    struct set *sets;
};


struct cache initCache(long long noSets, int noLines) {
    struct cache newCache;
    struct set newSet;
    struct line newLine;
    int setIndex, lineIndex;
    
    newCache.sets = (struct set*) malloc(sizeof(struct set) * noSets);
    
    for(setIndex = 0; setIndex < noSets; setIndex++) {
        newSet.lines = (struct line*) malloc(sizeof(struct line) *noLines);    
        newCache.sets[setIndex] = newSet;
        for (lineIndex = 0; lineIndex < noLines; lineIndex++) 
        {
            newLine.latest = 0;
            newLine.valid = 0;
            newLine.tag = 0; 
            newSet.lines[lineIndex] = newLine;
        }
    }
    return newCache;
}

int detectEmptyLine(struct set s, struct cacheDef d) {
    int nolines = d.E;
    int indLine;
    for(indLine = 0; indLine < nolines; indLine++) {
        if(s.lines[indLine].valid == 0) {
            return indLine;
        }
    }
    return -1;
}

int detectEvictLine(struct set s, struct cacheDef d, int *usedLines) {
    int noLines = d.E;
    int maxFreqUsage = s.lines[0].latest;
    int minFreqUsage = s.lines[0].latest;
    int minFreqUsage_index = 0;
    int indexOfLine;

    for (indexOfLine = 1; indexOfLine < noLines; indexOfLine++) {
        if (minFreqUsage > s.lines[indexOfLine].latest) {
            minFreqUsage_index = indexOfLine;   
            minFreqUsage = s.lines[indexOfLine].latest;
        }

        if (maxFreqUsage < s.lines[indexOfLine].latest) {
            maxFreqUsage = s.lines[indexOfLine].latest;
        }
    }

    usedLines[0] = minFreqUsage;
    usedLines[1] = maxFreqUsage;

    return minFreqUsage_index;

}

struct cacheDef accessCache(struct cache c, struct cacheDef d, address add) {
    int indLine, checkCache = 1;
    int noLines = d.E;
    int prevHit = d.hits;
    int tagSize = (64 - (d.s + d.b));
    
    address inputTag = add >> (d.s + d.b);
    unsigned long long temp = add << tagSize;
    unsigned long long setIndex = temp >> (tagSize + d.b);
    
    struct set nSet = c.sets[setIndex];
    
    for(indLine = 0; indLine < noLines; indLine++) {
        if (nSet.lines[indLine].valid) {    
            if (nSet.lines[indLine].tag == inputTag) {
                nSet.lines[indLine].latest++;
                d.hits++;
            }
        } else if (!(nSet.lines[indLine].valid) && (checkCache)) {
                checkCache = 0;
        }
    }
    
    if(prevHit == d.hits) {
        d.misses++;
    } else {
        return d;
    }
    
    int *usedLines = (int*) malloc(sizeof(int)*2);
    int minInd = detectEvictLine(nSet, d, usedLines);
    
    if(checkCache) {
        d.evictions++;
        nSet.lines[minInd].tag = inputTag;
        nSet.lines[minInd].latest = usedLines[1] + 1;
    } else {
        int empty_ind = detectEmptyLine(nSet, d);
        nSet.lines[empty_ind].tag = inputTag;
        nSet.lines[empty_ind].valid = 1;
        nSet.lines[empty_ind].latest = usedLines[1] + 1;
    }
    free(usedLines);
    return d;
}

int main(int argc, char *argv[]) {
    
    int opt, size;
    struct cacheDef def;
    char *trace_file;
    struct cache compCache;
    long long noOfSets;
    FILE *openFile;
    address a;
    char inst;
    while((opt = getopt(argc, argv, "s:E:b:t:vh")) != -1) {
        switch(opt) {
            case 's': def.s = atoi(optarg);            
            break;
            case 'E': def.E = atoi(optarg);
            break;
            case 'b': def.b = atoi(optarg);
            break;
            case 't': trace_file = optarg;
            break;
            default:
            break;
        }
    }
    
    noOfSets = pow(2, def.s);
    def.hits = 0;
    def.misses = 0;
    def.evictions = 0;
    compCache = initCache(noOfSets, def.E);
    openFile = fopen(trace_file, "r");
    
    if(openFile != NULL) {
        while(fscanf(openFile, " %c %llx,%d", &inst, &a, &size) == 3) {
            printf("%lld", a);
            switch(inst) {
                case 'I':
                    break;
                case 'L':
                    def = accessCache(compCache, def, a);
                    break;
                case 'S':
                    def = accessCache(compCache, def, a);
                    break;
                case 'M':
                    def = accessCache(compCache, def, a);
                    def = accessCache(compCache, def, a);
                    break;
                default:
                    break;
            }
        }
    }
    
    // printSummary(def.hits, def.misses, def.evictions);
    fclose(openFile);
    return 0;
}
