# Contributor's Guide

## Triggering a New Release for Circom Circuits

To trigger a release build:

1. Create and push a tag in the format `circom-circuits_vX.Y.Z`.
2. This will automatically trigger the `.github/workflows/build_circuits.yml` workflow.
3. Once the workflow finishes, the generated artifacts will be attached to a new release.

> Currently, releases published this way are marked as **Draft** and **Pre-Release** to ensure that the changelog and pre-release steps are manually reviewed first.

### Example

```bash
git tag circom_circuits-v1.2.3 -m "Release for Circom Circuits v1.2.3"
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

