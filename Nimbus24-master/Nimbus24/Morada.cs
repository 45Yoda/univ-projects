namespace Nimbus24
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Morada")]
    public partial class Morada
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Morada()
        {
            Serviço = new HashSet<Serviço>();
        }

        public int id { get; set; }

        [StringLength(50)]
        public string rua { get; set; }

        public int? porta { get; set; }

        [StringLength(50)]
        public string codPostal { get; set; }

        [StringLength(50)]
        public string Cidade_cidade { get; set; }

        public virtual Cidade Cidade { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Serviço> Serviço { get; set; }
    }
}
