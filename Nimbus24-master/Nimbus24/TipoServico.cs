namespace Nimbus24
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("TipoServico")]
    public partial class TipoServico
    {
        public int id { get; set; }

        public string tipo { get; set; }

        public decimal? preco { get; set; }

        public int? id_Prestador { get; set; }

        public int? negociavel { get; set; }

        public virtual Prestador Prestador { get; set; }
    }
}
