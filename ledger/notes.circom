//test
pragma circom 2.1.9;

include "../hash_bn/poseidon2_hash.circom";
include "../misc/constants.circom";

template derive_secret_key(){
    signal input starting_slot;
    signal input secrets_root;
    signal output out;

    component hash = Poseidon2_hash(3);
    component dst = NOMOS_POL_SK_V1();
    hash.inp[0] <== dst.out;
    hash.inp[1] <== starting_slot;
    hash.inp[2] <== secrets_root;

    out <== hash.out;
}

template derive_public_key(){
    signal input secret_key;
    signal output out;

    component hash = Poseidon2_hash(2);
    component dst = NOMOS_KDF();
    hash.inp[0] <== dst.out;
    hash.inp[1] <== secret_key;
    out <== hash.out;
}