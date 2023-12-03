namespace Nimbus24
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Avaliação
    {
        public int id { get; set; }

        public int? avaliacao { get; set; }

        [StringLength(50)]
        public string obs { get; set; }

        public int? Servico_id { get; set; }

        public virtual Serviço Serviço { get; set; }
    }
}
