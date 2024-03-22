#include <stdio.h>
#include <stdlib.h>

double steuerRechner(double betrag);

int main()
{
    char typ;
    double betrag;
    double guthaben = 100;
    double einnahmen = 0;
    double ausgaben = 0;
    double steuernGesamt = 0;
    int einnahmenCount = 0;
    int ausgabenCount = 0;

    printf("\nGuthaben: %.2lf Euro", guthaben);

    while (1) {
        printf("\nTyp: ");
        scanf(" %c", &typ);             // Leerzeichen vor %c, um den vorherigen Zeilenumbruch (Enter) zu ignorieren

        if (typ == '=')
            break;

        printf("\nBetrag in Euro: ");
        scanf("%lf", &betrag);

        if (betrag < 0) {
            printf("\nDer Betrag kann nicht negativ sein.");
            printf("\nGuthaben: %.2lf Euro", guthaben);
            continue;
        }

        if (typ == 'e') {
            double steuern = steuerRechner(betrag);
            printf("\nGezahlte Steuern: %.2lf Euro", steuern);
            einnahmenCount++;
            steuernGesamt += steuern;
            betrag -= steuern;          // Neuer Betrag nach Steuerabzug
            einnahmen += betrag;
            guthaben += betrag;
        } else if (typ == 's') {
            einnahmenCount++;
            einnahmen += betrag;
            guthaben += betrag;
        } else if (typ == 'k') {
            if (betrag > guthaben) {
                printf("\nDiese Kosten koennen nicht bezahlt werden.");
            } else {
                ausgabenCount++;
                ausgaben += betrag;
                guthaben -= betrag;
            }
        }
        printf("\nGuthaben: %.2lf Euro", guthaben);
    }

    // Artithmetisches Mittel bzw. Durchschnitt (und wenn keine einnahmen/ausgaben, dann Wert 0)
    double einnahmenMittel = einnahmenCount > 0 ? (einnahmen / einnahmenCount) : 0;
    double ausgabenMittel = ausgabenCount > 0 ? (ausgaben / ausgabenCount) : 0;

    printf("\nRestguthaben: %.2lf Euro", guthaben);
    printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", einnahmenCount, einnahmenMittel);
    printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", ausgabenCount, ausgabenMittel);
    printf("\nGezahlte Steuern: %.2lf Euro", steuernGesamt);

    return 0;
}

double steuerRechner(double betrag)
{
    double tax = 0;

    if (betrag > 20 && betrag <= 50)
        tax = (betrag - 20) * 0.1;              // 10% besteuert
    else if (betrag > 50 && betrag <= 200)
        tax = ((betrag - 50) * 0.2) + 3;        // 20% besteuert
    else if (betrag > 200)
        tax = ((betrag - 200) * 0.4) + 33;      // 40% besteuert
    return tax;
}
