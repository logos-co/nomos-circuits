//test
pragma circom 2.1.9;

include "../circomlib/circuits/bitify.circom";
include "../circomlib/circuits/comparators.circom";

// int.from_bytes(b"LEAD_V1", byteorder="little") = 13887241025832268
template LEAD_V1(){
    signal output out;
    out <== 13887241025832268;
}


// int.from_bytes(b"NOMOS_POL_SK_V1", byteorder="little") = 256174383281726064679014503048630094
template NOMOS_POL_SK_V1(){
    signal output out;
    out <== 256174383281726064679014503048630094;
}


// int.from_bytes(b"NOMOS_NONCE_CONTRIB_V1", byteorder="little") = 18459309511848927313552932915476467038165525790019406
template NOMOS_NONCE_CONTRIB_V1(){
    signal output out;
    out <== 18459309511848927313552932915476467038165525790019406;
}


// int.from_bytes(b"NOMOS_KDF", byteorder="little") = 1296193216988918402894
template NOMOS_KDF(){
    signal output out;
    out <== 1296193216988918402894;
}


// int.from_bytes(b"NOMOS_NOTE_ID_V1", byteorder="little") = 65580641562429851895355409762135920462
template NOMOS_NOTE_ID_V1(){
    signal output out;
    out <== 65580641562429851895355409762135920462;
}


// int.from_bytes(b"SELECTION_RANDOMNESS_V1", byteorder="little") = 4725583332308041445519605499429790922252397838206780755
template SELECTION_RANDOMNESS_V1(){
    signal output out;
    out <== 4725583332308041445519605499429790922252397838206780755;
}


// int.from_bytes(b"KEY_NULLIFIER_V1", byteorder="little") = 65580642670359595206974785265459610955
template KEY_NULLIFIER_V1(){
    signal output out;
    out <== 65580642670359595206974785265459610955;
}


// int.from_bytes(b"REWARD_VOUCHER", byteorder="little") = 1668646695034522932676805048878418
template REWARD_VOUCHER(){
    signal output out;
    out <== 1668646695034522932676805048878418;
}


// int.from_bytes(b"VOUCHER_NF", byteorder="little") = 332011368467182873038678
template VOUCHER_NF(){
    signal output out;
    out <== 332011368467182873038678;
}