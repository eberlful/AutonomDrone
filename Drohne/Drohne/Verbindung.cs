using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Drohne
{
    class Verbindung
    {
        /*
         * Protokollerläuterung
         * 
         * 
         * 
         * 
         */
        private Boolean statusVerbindung = false;

        public Verbindung()
        {

        }

        private Boolean verbinden()
        {

            return true;
        }

        /*******************************************
         *          Drohne -> Station
         *******************************************
         * Byte[0] = GPS
         * Byte[1] = Radarsensor 1
         * Byte[2] = Radarsensor 2
         * Byte[3] = Radarsensor 3
         * Byte[4] = Radarsensor 4
         * Byte[5] = Radarsensor 5
         * Byte[6] = Akkustand (256/100) = 1%
         * Byte[7] = Aktuelle Höhe
         * Byte[8] = Ultraschallsensor 1
         * Byte[9] = Ultraschallsensor 2
         * Byte[10] = Ultraschallsensor 3
         * Byte[11] = Ultraschallsensor 4
         * Byte[12] = Ultraschallsensor 5
         * Byte[13] = Verbindungsqualität
         * Byte[14] = Checksumme
         */

        public Boolean makeDronePackage(Byte[] informations)
        {
            Boolean status = false;

            return status;
        }

        /******************************************
         *          Station -> Drohne
         ******************************************
         * Byte[0] = GPS return point
         * Byte[1] = Modus
         * Byte[2] = Steurwert Höhe
         * Byte[3] = Steuerwert Links
         * Byte[4] = Steuerwert Rechts
         * Byte[5] = Checksumme
         */
         
        public Boolean makeStationPackage(Byte [] informations)
        {
            Boolean status = false;

            return status;
        }

        public Boolean transmitMessage()
        {
            Boolean status = false;



            return status;
        }
    }
}
