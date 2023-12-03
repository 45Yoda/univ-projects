namespace Nimbus24
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Serviço
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Serviço()
        {
            Avaliação = new HashSet<Avaliação>();
        }

        public int id { get; set; }

        public decimal? preço { get; set; }

        public DateTime? data { get; set; }

        public int? estado { get; set; }

        public int? idCliente { get; set; }

        public int? idPrestador { get; set; }

        [StringLength(50)]
        public string descrição { get; set; }

        public int? morada_id { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Avaliação> Avaliação { get; set; }

        public virtual Cliente Cliente { get; set; }

        public virtual Morada Morada { get; set; }

        public virtual Prestador Prestador { get; set; }
    }
}
