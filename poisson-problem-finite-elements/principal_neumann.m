function principal_neumann(nom_maillage);
% =====================================================
%
% principal_neumann(nom_maillage);
%
% une routine pour la mise en oeuvre des EF P1 Lagrange
% pour l'equation de Laplace suivante, avec conditions de
% Neumann sur le maillage nom_maillage.msh
%
% | -\Delta u + u= f,   dans \Omega
% |         du/dn = 0,   sur le bord
%
% INPUT  * nom_maillage : racine du fichier de maillage .msh (string) 
%        * titre (optionel) un titre (string)
%
% OUTPUT une fenetre graphique
% =====================================================


% lecture du maillage et affichage
% ---------------------------------
[Nbpt,Nbtri,Coorneu,Refneu,Numtri,Reftri]=lecture_msh(nom_maillage);

% ----------------------
% calcul des matrices EF
% ----------------------

% declarations
% ------------
KK = sparse(Nbpt,Nbpt); % matrice de rigidite
MM = sparse(Nbpt,Nbpt); % matrice de rigidite
FF = zeros(Nbpt,1);     % vecteur second membre

% boucle sur les triangles
% ------------------------
for l=1:Nbtri
  
  % calcul des matrices elementaires du triangle l 
  
   [Kel]=matK_elem(Coorneu(Numtri(l,1),:),Coorneu(Numtri(l,2),:),...
		       Coorneu(Numtri(l,3),:));
           
   [Mel]=matM_elem(Coorneu(Numtri(l,1),:),Coorneu(Numtri(l,2),:),...
		       Coorneu(Numtri(l,3),:));
    
  % On fait l'assemmblage de la matrice globale et du second membre
  for i=1:3
        I = Numtri(l,i); %local vers global
    for j=1:3
        J = Numtri(l,j); %local vers global
        MM(I,J)= MM(I,J) + Mel(i,j);
        KK(I,J) = KK(I,J) + Kel(i,j);
    end
  end
end % for l

% Calcul du second membre F
% -------------------------
	% A COMPLETER
	% utiliser la routine f.m
FF = f(Coorneu(:,1),Coorneu(:,2));
LL = MM*FF;
% inversion
% ----------
UU = (MM+KK)\LL;

% visualisation
% -------------

max_value = max(UU, [], 'all');
disp(max_value)
affiche(UU, Numtri, Coorneu, sprintf('%s - max value : %f', nom_maillage, max_value));

%Validation de la solution 
%UU_exact = cos(pi*Coorneu(:,1)).*cos(2*pi*Coorneu(:,2));
% affiche(UU_exact, Numtri, Coorneu, sprintf('Solution exacte', nom_maillage));

%calcul de l’erreur
%norm_L2 = sqrt((UU_exact)'*MM*(UU_exact));
%norm_H1 = sqrt((UU_exact)'*KK*(UU_exact));
%erreur_L2 = sqrt((UU_exact-UU)'*MM*(UU_exact-UU));
%erreur_H1 = sqrt((UU_exact-UU)'*KK*(UU_exact-UU));
%disp(erreur_L2/norm_L2);
%disp(erreur_H1/norm_H1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                        fin de la routine
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

