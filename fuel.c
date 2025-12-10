#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "fuel.dat"
#define MAX_VEHICLE_LEN 100
#define MAX_FUELTYPE_LEN 50
#define MAX_DATE_LEN 20
#define MAX_PURPOSE_LEN 100
#define MAX_DRIVER_LEN 100

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int id;                         // Fuel Record ID
    char vehicle[MAX_VEHICLE_LEN];  // Vehicle Name / Vehicle Number
    float quantity;                 // Fuel Quantity (Litres)
    char fuelType[MAX_FUELTYPE_LEN]; // Diesel / Petrol
    char date[MAX_DATE_LEN];        // Date of filling
    char purpose[MAX_PURPOSE_LEN];  // Purpose (Travel / Delivery)
    char driver[MAX_DRIVER_LEN];    // Driver Contact / Name
} FuelRecord;

// ------------------ FUNCTION DECLARATIONS ------------------
void addFuel();
void viewFuel();
void searchFuel();
void updateFuel();
void deleteFuel();
int idExists(int id);
void saveFuel(FuelRecord f);
void loadFuel(FuelRecord fuel[], int *count);
void writeAllFuel(FuelRecord fuel[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n==============================\n");
        printf("       FUEL MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Fuel Record\n");
        printf("2. View All Records\n");
        printf("3. Search Fuel Record\n");
        printf("4. Update Fuel Record\n");
        printf("5. Delete Fuel Record\n");
        printf("6. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: addFuel(); break;
            case 2: viewFuel(); break;
            case 3: searchFuel(); break;
            case 4: updateFuel(); break;
            case 5: deleteFuel(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD FUEL RECORD ------------------
void addFuel() {
    FuelRecord f;

    printf("\n--- Add Fuel Record ---\n");
    printf("Enter Record ID: ");
    scanf("%d", &f.id);
    getchar();

    if (idExists(f.id)) {
        printf("Error: Record ID already exists!\n");
        return;
    }

    printf("Enter Vehicle Name/Number: ");
    fgets(f.vehicle, sizeof(f.vehicle), stdin);
    f.vehicle[strcspn(f.vehicle, "\n")] = '\0';

    printf("Enter Fuel Quantity (Litres): ");
    scanf("%f", &f.quantity);
    getchar();

    printf("Enter Fuel Type (Petrol/Diesel): ");
    fgets(f.fuelType, sizeof(f.fuelType), stdin);
    f.fuelType[strcspn(f.fuelType, "\n")] = '\0';

    printf("Enter Date (DD/MM/YYYY): ");
    fgets(f.date, sizeof(f.date), stdin);
    f.date[strcspn(f.date, "\n")] = '\0';

    printf("Enter Purpose: ");
    fgets(f.purpose, sizeof(f.purpose), stdin);
    f.purpose[strcspn(f.purpose, "\n")] = '\0';

    printf("Enter Driver Name/Contact: ");
    fgets(f.driver, sizeof(f.driver), stdin);
    f.driver[strcspn(f.driver, "\n")] = '\0';

    saveFuel(f);
    printf("Fuel record added successfully!\n");
}

// ------------------ SAVE FUEL RECORD ------------------
void saveFuel(FuelRecord f) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&f, sizeof(FuelRecord), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    FuelRecord f;
    while (fread(&f, sizeof(FuelRecord), 1, fp)) {
        if (f.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL FUEL RECORDS ------------------
void viewFuel() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    FuelRecord f;
    printf("\n%-10s %-20s %-10s %-12s %-12s %-20s %-15s\n",
           "ID", "Vehicle", "Quantity", "Fuel Type", "Date", "Purpose", "Driver");
    printf("---------------------------------------------------------------------------------------------\n");

    while (fread(&f, sizeof(FuelRecord), 1, fp)) {
        printf("%-10d %-20s %-10.2f %-12s %-12s %-20s %-15s\n",
               f.id, f.vehicle, f.quantity, f.fuelType,
               f.date, f.purpose, f.driver);
    }
    fclose(fp);
}

// ------------------ SEARCH FUEL RECORD ------------------
void searchFuel() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    FuelRecord f;

    printf("\nEnter Record ID to search: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(FuelRecord), 1, fp)) {
        if (f.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nVehicle: %s\nFuel Quantity: %.2f\nFuel Type: %s\nDate: %s\nPurpose: %s\nDriver: %s\n",
                   f.id, f.vehicle, f.quantity, f.fuelType, f.date, f.purpose, f.driver);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No record found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE FUEL RECORD ------------------
void updateFuel() {
    FuelRecord fuel[100];
    int count = 0, id, found = 0;

    loadFuel(fuel, &count);

    printf("\nEnter Record ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (fuel[i].id == id) {
            found = 1;

            printf("Enter new driver info: ");
            fgets(fuel[i].driver, sizeof(fuel[i].driver), stdin);
            fuel[i].driver[strcspn(fuel[i].driver, "\n")] = '\0';

            printf("Enter new purpose: ");
            fgets(fuel[i].purpose, sizeof(fuel[i].purpose), stdin);
            fuel[i].purpose[strcspn(fuel[i].purpose, "\n")] = '\0';

            printf("Enter new quantity: ");
            scanf("%f", &fuel[i].quantity);
            getchar();

            break;
        }
    }

    if (found) {
        writeAllFuel(fuel, count);
        printf("Record updated successfully.\n");
    } else {
        printf("Record ID not found.\n");
    }
}

// ------------------ DELETE FUEL RECORD ------------------
void deleteFuel() {
    FuelRecord fuel[100];
    int count = 0, id, found = 0;

    loadFuel(fuel, &count);

    printf("\nEnter Record ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (fuel[i].id == id) {
            found = 1;

            printf("Are you sure you want to delete record ID %d (Vehicle: %s)? (y/n): ", id, fuel[i].vehicle);
            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    fuel[j] = fuel[j + 1];

                count--;
                writeAllFuel(fuel, count);
                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Record ID not found.\n");
}

// ------------------ LOAD & WRITE ALL ------------------
void loadFuel(FuelRecord fuel[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;

    *count = 0;
    while (fread(&fuel[*count], sizeof(FuelRecord), 1, fp))
        (*count)++;
    
    fclose(fp);
}

void writeAllFuel(FuelRecord fuel[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(fuel, sizeof(FuelRecord), count, fp);
    fclose(fp);
}