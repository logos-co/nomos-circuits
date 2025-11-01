# Contributor's Guide

## Triggering a New Release for Nomos Circuits

To trigger a release build:

1. Create and push a tag in the format `vX.Y.Z`.
2. This will automatically trigger the `.github/workflows/build_circuits.yml` workflow.
3. Once the workflow finishes, the generated artifacts will be attached to a new release.

> Currently, releases published this way are marked as **Draft** and **Pre-Release** to ensure that the changelog and pre-release steps are manually reviewed first.

### Generated Artifacts

Each release includes the following artifacts:

#### Platform-Specific Binaries

For each supported platform (Linux x86_64, macOS aarch64, Windows x86_64):

- **Prover binaries** (`prover-{version}-{os}-{arch}.tar.gz`)
  Rapidsnark prover binaries for generating zk-SNARK proofs

- **Verifier binaries** (`verifier-{version}-{os}-{arch}.tar.gz`)
  Rapidsnark verifier binaries for verifying zk-SNARK proofs

- **Witness generators** (`{circuit}-{version}-{os}-{arch}.tar.gz`)
  Compiled C++ witness generator binaries for each circuit (PoL, PoQ, ZKSign, PoC)

#### Platform-Independent Proving Keys

- **Proving keys** (`{circuit}-{version}.zkey.tar.gz`)
  Groth16 proving keys (.zkey files) for each circuit, required for generating proofs

These proving keys are generated using the Hermez Powers of Tau ceremony (`powersOfTau28_hez_final_21.ptau`), which supports circuits with up to 2^21 (~2M) constraints. The keys are platform-independent and can be used with any compatible prover implementation.

### Example

```bash
git tag v1.2.3 -m "Release v1.2.3"
git push --tags
```

## Publishing the Release

After triggering the release, it will appear as a **Draft** and **Pre-Release**.  
Before making it public, make sure to:

1. **Review the changelog**  
   Ensure that all relevant changes are clearly listed and properly formatted.

2. **Confirm the pre-release checklist**  
   Verify that all required steps have been completed, then remove the checklist from the release notes.

Once everything looks good:

3. **Mark the release as published**  
   - Uncheck **“This is a pre-release.”**  
   - Publish the release (removing the Draft state).

> ⚡ **Important:** Nomos builds will only pick up the new circuits once the release is published as **Latest** (i.e. not marked as draft or pre-release).

