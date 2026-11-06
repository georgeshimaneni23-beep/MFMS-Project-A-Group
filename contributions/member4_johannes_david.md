# Member 4 Contribution Record

## Student Details
- Name: Johannes David
- Student Number: 225158787

## Role
Asset Management

## Contribution Summary
I developed the asset management module, including the asset storage design, the add, display and search functions, duplicate ID checking and the asset menu. I also connected the module to the reports module.

## Work Completed
- Wrote `assets.c` and `assets.h` for the asset module.
- Created `addAsset()` to read an asset's ID, name, type, purchase value, department and condition, and store them in parallel arrays (maximum 100 assets).
- Created `displayAssets()` to list all registered assets, or show a message when none exist.
- Created `searchAsset()` to find an asset by ID using a loop and show "not found" when there is no match.
- Created `assetMenu()` to provide the Asset Management menu (add, display, search, return to main menu).
- Created `showAssetReport()` so the Reports module can display the asset register.
- Used the shared input functions from `utils.c` (`readPositiveInt`, `readText`, `readNonNegativeFloat`, `readInt`) for all asset input.

## Validation Implemented
- Asset IDs must be a positive whole number.
- Duplicate asset IDs are rejected ("Asset ID already exists. Asset not added.").
- Asset name, type, department and condition cannot be empty.
- Purchase value cannot be negative or non-numeric.
- Adding is blocked with a message once the 100-asset limit is reached.

## Concepts Used
Parallel arrays, functions, loops, conditions, `switch` menu, input validation.

## Testing Performed
- Added assets, displayed them and searched by ID.
- Tested invalid input: letters instead of numbers, a negative purchase value, empty fields and a duplicate asset ID.
- Tested searching for an ID that does not exist.
- Confirmed the asset list appears correctly in Reports (option 5, then 4).

## Commit Count
My commits are recorded in the repository's Git history.

## Notes
The asset module was integrated into the main menu (option 4) and the reports menu with the rest of the group.
