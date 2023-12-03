namespace Nimbus24
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class Nimbus24Context : DbContext
    {
        public Nimbus24Context()
            : base("name=Nimbus24Context")
        {
        }

        public virtual DbSet<Avaliação> Avaliação { get; set; }
        public virtual DbSet<Cidade> Cidade { get; set; }
        public virtual DbSet<Cliente> Cliente { get; set; }
        public virtual DbSet<Morada> Morada { get; set; }
        public virtual DbSet<Prestador> Prestador { get; set; }
        public virtual DbSet<Serviço> Serviço { get; set; }
        public virtual DbSet<TipoServico> TipoServico { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Avaliação>()
                .Property(e => e.obs)
                .IsUnicode(false);

            modelBuilder.Entity<Cidade>()
                .Property(e => e.Cidade1)
                .IsUnicode(false);

            modelBuilder.Entity<Cidade>()
                .HasMany(e => e.Morada)
                .WithOptional(e => e.Cidade)
                .HasForeignKey(e => e.Cidade_cidade);

            modelBuilder.Entity<Cidade>()
                .HasMany(e => e.Prestador)
                .WithOptional(e => e.Cidade)
                .HasForeignKey(e => e.Cidade_cidade);

            modelBuilder.Entity<Cliente>()
                .Property(e => e.mail)
                .IsUnicode(false);

            modelBuilder.Entity<Cliente>()
                .Property(e => e.nome)
                .IsUnicode(false);

            modelBuilder.Entity<Cliente>()
                .Property(e => e.password)
                .IsUnicode(false);

            modelBuilder.Entity<Cliente>()
                .Property(e => e.contacto)
                .IsUnicode(false);

            modelBuilder.Entity<Cliente>()
                .HasMany(e => e.Serviço)
                .WithOptional(e => e.Cliente)
                .HasForeignKey(e => e.idCliente);

            modelBuilder.Entity<Cliente>()
                .HasMany(e => e.Prestador)
                .WithMany(e => e.Cliente)
                .Map(m => m.ToTable("Preferencia").MapLeftKey("id_Cliente").MapRightKey("id_Prestador"));

            modelBuilder.Entity<Morada>()
                .Property(e => e.rua)
                .IsUnicode(false);

            modelBuilder.Entity<Morada>()
                .Property(e => e.codPostal)
                .IsUnicode(false);

            modelBuilder.Entity<Morada>()
                .Property(e => e.Cidade_cidade)
                .IsUnicode(false);

            modelBuilder.Entity<Morada>()
                .HasMany(e => e.Serviço)
                .WithOptional(e => e.Morada)
                .HasForeignKey(e => e.morada_id);

            modelBuilder.Entity<Prestador>()
                .Property(e => e.nome)
                .IsUnicode(false);

            modelBuilder.Entity<Prestador>()
                .Property(e => e.mail)
                .IsUnicode(false);

            modelBuilder.Entity<Prestador>()
                .Property(e => e.password)
                .IsUnicode(false);

            modelBuilder.Entity<Prestador>()
                .Property(e => e.contacto)
                .IsUnicode(false);

            modelBuilder.Entity<Prestador>()
                .Property(e => e.Cidade_cidade)
                .IsUnicode(false);

            modelBuilder.Entity<Prestador>()
                .HasMany(e => e.Serviço)
                .WithOptional(e => e.Prestador)
                .HasForeignKey(e => e.idPrestador);

            modelBuilder.Entity<Prestador>()
                .HasMany(e => e.TipoServico)
                .WithOptional(e => e.Prestador)
                .HasForeignKey(e => e.id_Prestador);

            modelBuilder.Entity<Serviço>()
                .Property(e => e.preço)
                .HasPrecision(6, 2);

            modelBuilder.Entity<Serviço>()
                .Property(e => e.descrição)
                .IsUnicode(false);

            modelBuilder.Entity<Serviço>()
                .HasMany(e => e.Avaliação)
                .WithOptional(e => e.Serviço)
                .HasForeignKey(e => e.Servico_id);

            modelBuilder.Entity<TipoServico>()
                .Property(e => e.preco)
                .HasPrecision(6, 2);
        }
    }
}
